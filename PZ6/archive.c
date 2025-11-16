#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/*

Задание
Промоделировать процесс логирования информационной системы и
сохранения архива логов раз в определенный промежуток времени.
Для этого разработать две независимые программы.
1 Есть программа, которая каждую секунду пишет в файл одну
строку, содержащую время записи.
2 Есть другая программа, которая раз в пять секунд забирает этот
файл и перекладывает его в другой каталог, переименовывая. В
новом имени файла содержится время создания файла. Файл
сохраняется заархивированным

*/

int main() {
    int count = 0;
    while (count < 5) {
        sleep(2);

        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char timestamp[80];
        strftime(timestamp, 80, "%Y%m%d_%H%M%S", tm_info);

        char cmd[512];
        snprintf(
            cmd,
            sizeof(cmd),
            "\"C:\\\\Program Files\\\\7-Zip\\\\7z.exe\" a -tgzip C:\\\\Users\\\\ilya2\\\\Desktop\\\\University-C\\\\PZ6\\\\archive_%s.tar.gz C:\\\\Users\\\\ilya2\\\\Desktop\\\\University-C\\\\PZ6\\\\log.txt",
            timestamp
        );

        int ret = system(cmd);
        if (ret != 0) {
            fprintf(stderr, "Archiving command failed\n");
            continue;
        }

        FILE *file = fopen("C:\\\\Users\\\\ilya2\\\\Desktop\\\\University-C\\\\PZ6\\\\log.txt", "w");
        if (file != NULL) {
            fclose(file);
        }

        count++;
    }
    return 0;
}
