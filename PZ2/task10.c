#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string.h>

int main() {
    char input_filename[256];
    char output_filename[256];
    FILE *input_file, *output_file;
    int c;
    int number = 0;
    int sign = 1;
    int in_number = 0;
    
    strcpy(input_filename, "TXT/task10.txt");
    strcpy(output_filename, "TXT/task10_result.txt");
    
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
        if (isdigit(c)) {
            if (!in_number) {
                number = 0;
                sign = 1;
                in_number = 1;
            }
            number = number * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            if (!in_number) {
                sign = (c == '+') ? 1 : -1;
                number = 0;
                in_number = 1;
            } else {
                if (in_number) {
                    if (sign == -1) {
                        fprintf(output_file, "0");
                    } else {
                        fprintf(output_file, "%d", number);
                    }
                }
                sign = (c == '+') ? 1 : -1;
                number = 0;
            }
        } else {
            if (in_number) {
                if (sign == -1) {
                    fprintf(output_file, "0");
                } else {
                    fprintf(output_file, "%d", number);
                }
                in_number = 0;
                number = 0;
            }
            fputc(c, output_file);
        }
    }
    
    if (in_number) {
        if (sign == -1) {
            fprintf(output_file, "0");
        } else {
            fprintf(output_file, "%d", number);
        }
    }
    
    fclose(input_file);
    fclose(output_file);
    printf("Processing completed\n");
    return 0;
}
