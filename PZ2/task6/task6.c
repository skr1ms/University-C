#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char result_filename[256];
    char input_filename[256];
    FILE *result_file, *input_file;
    int c;
    int num_files;
    
    strcpy(result_filename, "result.txt");
    num_files = 2;
    
    result_file = fopen(result_filename, "w");
    if (result_file == NULL) {
        printf("Error creating result file\n");
        return 1;
    }
    
    strcpy(input_filename, "file1.txt");
        
        input_file = fopen(input_filename, "r");
        if (input_file == NULL) {
            printf("Error opening file %s\n", input_filename);
            fclose(result_file);
            return 1;
        }
        
        while ((c = fgetc(input_file)) != EOF) {
            fputc(c, result_file);
        }
        
        fclose(input_file);
        
        strcpy(input_filename, "file2.txt");
        input_file = fopen(input_filename, "r");
        if (input_file == NULL) {
            printf("Error opening file %s\n", input_filename);
            fclose(result_file);
            return 1;
        }
        
        while ((c = fgetc(input_file)) != EOF) {
            fputc(c, result_file);
        }
        
        fclose(input_file);
    
    fclose(result_file);
    printf("Files successfully merged into %s\n", result_filename);
    return 0;
}
