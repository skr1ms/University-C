#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_filename[256];
    char output_filename[256];
    FILE *input_file, *output_file;
    int c;
    int line_length = 0;
    
    strcpy(input_filename, "TXT/task14.txt");
    strcpy(output_filename, "TXT/task14_result.txt");
    
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
    
    while ((c = fgetc(input_file)) != EOF) {
        if (c == '\n' || c == '\r') {
            continue;
        }
        
        fputc(c, output_file);
        line_length++;
        
        if (c == '.' || line_length == 60) {
            fputc('\n', output_file);
            line_length = 0;
        }
    }
    
    if (line_length > 0) {
        fputc('\n', output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    printf("Reformatting completed\n");
    return 0;
}
