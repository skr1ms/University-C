#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char filename[256];
    FILE *input_file, *output_file;
    char line[1000];
    
    strcpy(filename, "TXT/task9.txt");
    
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    output_file = fopen("temp_file", "w");
    if (output_file == NULL) {
        printf("Error creating temp file\n");
        fclose(input_file);
        return 1;
    }
    
    while (fgets(line, sizeof(line), input_file)) {
        sort_string(line);
        fputs(line, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    remove(filename);
    rename("temp_file", filename);
    printf("Sorting completed\n");
    return 0;
}
