#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
Вопросы:
1. Какие существуют способы обращения к файлу?
Через высокоуровневый stdio (fopen/fread/fwrite/fclose) и низкоуровневый POSIX (open/read/write/close).
2. Какой тип данных у переменной, получающей доступ к файлу?
Для stdio — FILE*, для POSIX — целочисленный файловый дескриптор (int).
3. Какие флаги открытия файла Вы знаете?
O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_TRUNC, O_APPEND, O_EXCL, O_SYNC и др.
4. Как закрыть доступ к файлу?
fclose(FILE*) для stdio, close(int fd) для POSIX.
5. Что такое mode, и как строка mode формируется?
mode — права доступа при создании (например, 0644); формируется побитовыми масками rwx для owner/group/others.

Задание
Решить задачу, с номером остатка от деления Вашего номера в журнале на
10. При решении опираться на получение файлового дискриптора с
использованием функций open(...), read(...), write(...).

9. В данном файле символы каждой строки упорядочить по алфавиту

*/

static int cmp_uchar(const void *a, const void *b) {
	unsigned char ua = *(const unsigned char *)a;
	unsigned char ub = *(const unsigned char *)b;
	return (ua > ub) - (ua < ub);
}

int main(int argc, char **argv) {
	const char *in_path = (argc >= 2) ? argv[1] : "input.txt";
	const char *out_path = (argc >= 3) ? argv[2] : "output.txt";

	int in_fd = open(in_path, O_RDONLY);
	if (in_fd < 0) {
		perror("open input");
		return 1;
	}
	int out_fd = open(out_path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (out_fd < 0) {
		perror("open output");
		close(in_fd);
		return 1;
	}

	const size_t BUF_SZ = 4096;
	unsigned char buf[4096];
	unsigned char *line = NULL;
	size_t line_cap = 0;
	size_t line_len = 0;

	for (;;) {
		ssize_t n = read(in_fd, buf, BUF_SZ);
		if (n < 0) {
			if (errno == EINTR) continue;
			perror("read");
			break;
		}
		if (n == 0) {
			break;
		}
		for (ssize_t i = 0; i < n; i++) {
			unsigned char c = buf[i];
			if (c == '\n') {
				if (line_len > 0) {
					qsort(line, line_len, 1, cmp_uchar);
					if (write(out_fd, line, line_len) < 0) {
						perror("write line");
						goto done;
					}
				}
				if (write(out_fd, "\n", 1) < 0) {
					perror("write nl");
					goto done;
				}
				line_len = 0;
				continue;
			}
			if (line_len + 1 > line_cap) {
				size_t new_cap = (line_cap == 0) ? 128 : (line_cap * 2);
				unsigned char *new_mem = (unsigned char *)realloc(line, new_cap);
				if (!new_mem) {
					perror("realloc");
					goto done;
				}
				line = new_mem;
				line_cap = new_cap;
			}
			line[line_len++] = c;
		}
	}
	if (line_len > 0) {
		qsort(line, line_len, 1, cmp_uchar);
		if (write(out_fd, line, line_len) < 0) {
			perror("write last line");
		}
	}

done:
	free(line);
	close(out_fd);
	close(in_fd);
	return 0;
}