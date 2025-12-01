#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_NAME 100
#define RECORDS 10

typedef struct {
    char name[MAX_NAME];
    int pages;
} Book;

int locked[RECORDS];

void lock_all() {
    for (int i = 0; i < RECORDS; i++)
        locked[i] = 1;
}

void unlock_record(int record_num) {
    locked[record_num] = 0;
}

void print_file(int fd) {
    Book book;
    for (int i = 0; i < RECORDS; i++) {
        if (locked[i]) {
            printf("%d: [LOCKED]\n", i + 1);
        } else {
            lseek(fd, i * sizeof(Book), SEEK_SET);
            read(fd, &book, sizeof(Book));
            printf("%d: %s - %d pages\n", i + 1, book.name, book.pages);
        }
    }
    printf("\n");
}

int count_available() {
    int cnt = 0;
    for (int i = 0; i < RECORDS; i++)
        if (!locked[i]) cnt++;
    return cnt;
}

int main() {
    Book books[RECORDS];
    FILE *f;
    int fd;
    char line[256];
    memset(locked, 0, sizeof(locked));
    
    f = fopen("books.txt", "r");
    for (int i = 0; i < RECORDS; i++) {
        fgets(line, sizeof(line), f);
        char *last_space = strrchr(line, ' ');
        books[i].pages = atoi(last_space + 1);
        *last_space = '\0';
        strncpy(books[i].name, line, MAX_NAME - 1);
        books[i].name[MAX_NAME - 1] = '\0';
    }
    fclose(f);

    fd = open("books.bin", O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(fd, books, sizeof(books));
    lseek(fd, 0, SEEK_SET);

    printf("=== Запрещено чтение всего файла ===\n");
    lock_all();
    print_file(fd);

    printf("=== Разрешено чтение третьей записи ===\n");
    unlock_record(2);
    print_file(fd);

    printf("Количество доступных записей: %d\n", count_available());

    close(fd);
    return 0;
}
