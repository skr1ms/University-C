#include <stdio.h>
#include <errno.h>

/*
Разработать алгоритм, приводящий к ошибке. Написать программу
на языке си с обработчиком ошибки. Спровоцировать срабатывание
ошибки. Вывести информацию из обработчика на консоль.
Ошибка для провоцирования: Операция не разрешена
*/

int main() {
  int a = 1;
  int b = 0;
  if (b == 0) {
    errno = EINVAL;
    fprintf(stderr, "Error: division by zero\n");
    return errno;
  }
  int c = a / b;
  return 0;
}