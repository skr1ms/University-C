#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *file;
    char line[32];
    int length_count[31] = {0};
    int line_length;
    
    strcpy(filename, "TXT/task3.txt");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), file)) {
        line_length = strlen(line);
        if (line[line_length - 1] == '\n') {
            line_length--;
        }
        if (line_length >= 1 && line_length <= 30) {
            length_count[line_length]++;
        }
    }
    
    fclose(file);
    
    printf("Number of lines by length:\n");
    for (int i = 1; i <= 30; i++) {
        if (length_count[i] > 0) {
            printf("Length %d: %d lines\n", i, length_count[i]);
        }
    }
    
    return 0;
}
