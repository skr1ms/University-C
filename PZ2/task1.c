#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char filename[256];
    char substring[256];
    char line[1000];
    FILE *file;
    
    strcpy(filename, "TXT/task1.txt");
    strcpy(substring, "test");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, substring) != NULL) {
            printf("%s", line);
        }
    }
    
    fclose(file);
    return 0;
}
