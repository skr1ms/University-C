#include <ctype.h>
#include <stdio.h>
#include <string.h>


int count_words(char *str) {
  int count = 0;
  int in_word = 0;

  for (int i = 0; str[i]; i++) {
    if (isspace(str[i])) {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      count++;
    }
  }
  return count;
}

int main() {
  char line[1024];

  while (fgets(line, sizeof(line), stdin)) {
    line[strcspn(line, "\n")] = 0;
    printf("%s %d\n", line, count_words(line));
  }

  return 0;
}
