#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_filename[256];
    char output_filename[256];
    FILE *input_file, *output_file;
    char line[60];
    
    strcpy(input_filename, "TXT/task13.txt");
    strcpy(output_filename, "TXT/task13_result.txt");
    
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error creating file\n");
        fclose(input_file);
        return 1;
    }
    
    while (fgets(line, sizeof(line), input_file)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            len--;
        }
        
        fputs(line, output_file);
        
        for (int i = len; i < 50; i++) {
            fputc(' ', output_file);
        }
        fputc('\n', output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    printf("File created\n");
    return 0;
}
