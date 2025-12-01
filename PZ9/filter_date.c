#include <stdio.h>
#include <string.h>

int main() {
  char line[1024];

  while (fgets(line, sizeof(line), stdin)) {
    if (strncmp(line, "03.05.2024", 10) == 0) {
      printf("%s", line);
    }
  }

  return 0;
}
