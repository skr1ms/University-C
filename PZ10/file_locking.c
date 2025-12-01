#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAX_NAME 100
#define RECORDS 10

typedef struct {
  char name[MAX_NAME];
  int pages;
} Book;

void lock_record(int fd, int record_num, int lock_type) {
  struct flock fl;
  fl.l_type = lock_type;
  fl.l_whence = SEEK_SET;
  fl.l_start = record_num * sizeof(Book);
  fl.l_len = sizeof(Book);
  fcntl(fd, F_SETLK, &fl);
}

void print_file(int fd) {
  Book book;
  lseek(fd, 0, SEEK_SET);

  for (int i = 0; i < RECORDS; i++) {
    struct flock fl;
    fl.l_type = F_RDLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = i * sizeof(Book);
    fl.l_len = sizeof(Book);

    if (fcntl(fd, F_GETLK, &fl) == 0 && fl.l_type == F_UNLCK) {
      lseek(fd, i * sizeof(Book), SEEK_SET);
      read(fd, &book, sizeof(Book));
      printf("%d: %s - %d pages\n", i + 1, book.name, book.pages);
    } else {
      printf("%d: [LOCKED]\n", i + 1);
    }
  }
  printf("\n");
}

int count_available(int fd) {
  int count = 0;

  for (int i = 0; i < RECORDS; i++) {
    struct flock fl;
    fl.l_type = F_RDLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = i * sizeof(Book);
    fl.l_len = sizeof(Book);

    if (fcntl(fd, F_GETLK, &fl) == 0 && fl.l_type == F_UNLCK) {
      count++;
    }
  }

  return count;
}

int main() {
  Book books[RECORDS];
  FILE *f;
  int fd;

  f = fopen("books.txt", "r");
  for (int i = 0; i < RECORDS; i++) {
    fscanf(f, " %[^\n]", books[i].name);
    char *last_space = strrchr(books[i].name, ' ');
    books[i].pages = atoi(last_space + 1);
    *last_space = '\0';
  }
  fclose(f);

  fd = open("books.bin", O_RDWR | O_CREAT | O_TRUNC, 0644);
  write(fd, books, sizeof(books));

  printf("=== Запрещено чтение третьей записи ===\n");
  lock_record(fd, 2, F_WRLCK);
  print_file(fd);

  printf("=== Разрешено чтение третьей записи ===\n");
  lock_record(fd, 2, F_UNLCK);
  print_file(fd);

  printf("Количество доступных записей: %d\n", count_available(fd));

  close(fd);
  return 0;
}
