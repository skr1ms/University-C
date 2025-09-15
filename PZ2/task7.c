#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string.h>

int main() {
    char input_filename[256];
    FILE *input_file, *output_file;
    int c;
    
    strcpy(input_filename, "TXT/task7.txt");
    
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    output_file = fopen("result.txt", "w");
    if (output_file == NULL) {
        printf("Error creating file result.txt\n");
        fclose(input_file);
        return 1;
    }
    
    while ((c = fgetc(input_file)) != EOF) {
        if (isupper(c)) {
            c = tolower(c);
        }
        fputc(c, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    printf("File result.txt created\n");
    return 0;
}
