#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256], output_filename[256];
    FILE *file, *output_file;
    int cols;
    int **matrix;
    int size;
    
    strcpy(filename, "TXT/task18.txt");
    strcpy(output_filename, "TXT/task18_result.txt");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    fscanf(file, "%d", &cols);
    
    size = 0;
    while (fscanf(file, "%*d") == 0) {
        size++;
    }
    
    fclose(file);
    file = fopen(filename, "r");
    fscanf(file, "%d", &cols);
    
    matrix = malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    
    int row = 0, col = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        matrix[row][col] = num;
        col++;
        if (col == cols) {
            row++;
            col = row;
        }
    }
    
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < i; j++) {
            matrix[i][j] = matrix[j][i];
        }
    }
    
    output_file = fopen(output_filename, "w");
    fprintf(output_file, "%d\n", cols);
    
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(output_file, "%d ", matrix[i][j]);
        }
        fprintf(output_file, "\n");
    }
    
    fclose(file);
    fclose(output_file);
    
    for (int i = 0; i < cols; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    printf("Full matrix created\n");
    return 0;
}
