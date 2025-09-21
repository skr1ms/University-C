#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int is_perfect_square(int n) {
    if (n < 0) return 0;
    int root = (int)sqrt(n);
    return root * root == n;
}

int count_digits(int n) {
    if (n == 0) return 1;
    int count = 0;
    if (n < 0) {
        count++;
        n = -n;
    }
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    char filename[256];
    FILE *input_file, *output_file;
    int num;
    int count = 0;
    
    strcpy(filename, "TXT/task22.txt");
    
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
        fprintf(output_file, "%d ", num);
        if (is_perfect_square(num)) {
            count++;
            for (int i = 0; i < count_digits(num); i++) {
                fprintf(output_file, "-");
            }
            fprintf(output_file, " ");
        } else {
            for (int i = 0; i < count_digits(num); i++) {
                fprintf(output_file, " ");
            }
            fprintf(output_file, " ");
        }
    }
    
    fclose(input_file);
    fclose(output_file);
    
    remove(filename);
    rename("temp_output", filename);
    
    printf("Found %d perfect squares\n", count);
    return 0;
}
