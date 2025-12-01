#include <ctype.h>
#include <stdio.h>


int main() {
  int digit_count = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (isdigit(c)) {
      digit_count++;
    }
  }

  printf("%d\n", digit_count);

  return 0;
}
