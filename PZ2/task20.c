#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *file;
    char line[1000];
    char longest_line[1000] = "";
    int max_length = 0;
    
    strcpy(filename, "TXT/task20.txt");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), file)) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            length--;
        }
        if (length > max_length) {
            max_length = length;
            strcpy(longest_line, line);
        }
    }
    
    fclose(file);
    
    printf("Longest line (%d characters):\n%s\n", max_length, longest_line);
    return 0;
}
