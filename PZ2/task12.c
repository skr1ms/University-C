#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *file;
    char line[1000];
    int count = 0;
    
    strcpy(filename, "TXT/task12.txt");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        if (len > 1 && line[len - 1] == '\n') {
            len--;
        }
        if (len > 0 && line[0] == line[len - 1]) {
            count++;
        }
    }
    
    fclose(file);
    printf("Number of lines starting and ending with same character: %d\n", count);
    return 0;
}
