#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_perfect_square(int n) {
    if (n < 0) return 0;
    int root = (int)sqrt(n);
    return root * root == n;
}

int main() {
    char filename[256];
    FILE *input_file, *output_file;
    int num;
    int count = 0;
    
    strcpy(filename, "TXT/task21.txt");
    
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    output_file = fopen("temp_output", "w");
    if (output_file == NULL) {
        printf("Error creating temp file\n");
        fclose(input_file);
        return 1;
    }
    
    while (fscanf(input_file, "%d", &num) == 1) {
        if (is_perfect_square(num)) {
            count++;
            fprintf(output_file, "%d\n", num);
            for (int i = 0; i < (int)log10(num) + 1; i++) {
                fprintf(output_file, "-");
            }
            fprintf(output_file, "\n");
        } else {
            fprintf(output_file, "%d\n", num);
        }
    }
    
    fclose(input_file);
    fclose(output_file);
    
    remove(filename);
    rename("temp_output", filename);
    
    printf("Found %d perfect squares\n", count);
    return 0;
}
