#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_filename[256];
    char output_filename[256];
    FILE *input_file, *output_file;
    double prev_num, curr_num;
    int length = 1;
    int first = 1;
    
    strcpy(input_filename, "TXT/task15.txt");
    strcpy(output_filename, "TXT/task15_result.txt");
    
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
    
    if (fscanf(input_file, "%lf", &prev_num) != 1) {
        printf("File is empty\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    
    while (fscanf(input_file, "%lf", &curr_num) == 1) {
        if (curr_num < prev_num) {
            length++;
        } else {
            if (length > 1) {
                if (!first) {
                    fprintf(output_file, " ");
                }
                fprintf(output_file, "%d", length);
                first = 0;
            }
            length = 1;
        }
        prev_num = curr_num;
    }
    
    if (length > 1) {
        if (!first) {
            fprintf(output_file, " ");
        }
        fprintf(output_file, "%d", length);
    }
    
    fclose(input_file);
    fclose(output_file);
    printf("Processing completed\n");
    return 0;
}
