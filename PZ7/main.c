#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/*

Задание
Настроить виртуальную операционную систему:
Создать в системе три пользователя и одну группу пользователей. При
этом User1 и User2 входят в Group1, и User3 не входит в группу.
Выполнить индивидуальное задание согласно номеру в журнале, кратно 5.
4. Создать файл с текстом от имени администратора. Разрешить его менять
группе, запретить читать всем остальным. Разработать программу,
демонстрирующую корректность настройки.

*/

int main() {
    int fd = open("task4.txt", O_CREAT | O_TRUNC | O_WRONLY, 0600);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    const char *text = "File text for variant 4\n";
    if (write(fd, text, strlen(text)) < 0) {
        perror("write");
        close(fd);
        return 1;
    }
    close(fd);

    if (chmod("task4.txt", 0660) != 0) {
        perror("chmod");
        return 1;
    }

    struct stat st;
    if (stat("task4.txt", &st) != 0) {
        perror("stat");
        return 1;
    }

    printf("Permissions: %o\n", st.st_mode & 0777);
    printf("Owner: read=%s, write=%s\n",
           (st.st_mode & S_IRUSR) ? "OK" : "NO",
           (st.st_mode & S_IWUSR) ? "OK" : "NO");
    printf("Group: read=%s, write=%s\n",
           (st.st_mode & S_IRGRP) ? "OK" : "NO",
           (st.st_mode & S_IWGRP) ? "OK" : "NO");
    printf("Others: read=%s, write=%s\n",
           (st.st_mode & S_IROTH) ? "OK" : "NO",
           (st.st_mode & S_IWOTH) ? "OK" : "NO");

    int fd_owner_test = open("task4.txt", O_WRONLY | O_APPEND);
    printf("Owner write test: %s\n", (fd_owner_test >= 0) ? "OK" : "NO");
    if (fd_owner_test >= 0) close(fd_owner_test);

    return 0;
}

