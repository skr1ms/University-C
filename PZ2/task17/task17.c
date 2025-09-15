#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename1[256], filename2[256], output_filename[256];
    FILE *file1, *file2, *output_file;
    int cols1, cols2, rows1, rows2;
    int **matrix1, **matrix2, **result;
   
    strcpy(filename1, "matrix1.txt");
    strcpy(filename2, "matrix2.txt");
    strcpy(output_filename, "result.txt");
   
    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
   
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files\n");
        return 1;
    }
   
    fscanf(file1, "%d %d", &rows1, &cols1);
    fscanf(file2, "%d %d", &rows2, &cols2);
   
    if (cols1 != rows2) {
        printf("Number of columns of first matrix (%d) must equal number of rows of second matrix (%d)\n", cols1, rows2);
        printf("Matrix1 dimensions: %d x %d\n", rows1, cols1);
        printf("Matrix2 dimensions: %d x %d\n", rows2, cols2);
        fclose(file1);
        fclose(file2);
        return 1;
    }
   
    matrix1 = malloc(rows1 * sizeof(int*));
    matrix2 = malloc(rows2 * sizeof(int*));
    result = malloc(rows1 * sizeof(int*));
   
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = malloc(cols1 * sizeof(int));
        result[i] = malloc(cols2 * sizeof(int));
    }
   
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = malloc(cols2 * sizeof(int));
    }
   
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            if (fscanf(file1, "%d", &matrix1[i][j]) != 1) {
                printf("Error reading matrix1 element at position [%d][%d]\n", i, j);
                return 1;
            }
        }
    }
   
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            if (fscanf(file2, "%d", &matrix2[i][j]) != 1) {
                printf("Error reading matrix2 element at position [%d][%d]\n", i, j);
                return 1;
            }
        }
    }
   
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
   
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error creating output file\n");
        return 1;
    }
    
    fprintf(output_file, "%d %d\n", rows1, cols2);
   
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            fprintf(output_file, "%d", result[i][j]);
            if (j < cols2 - 1) fprintf(output_file, " ");
        }
        fprintf(output_file, "\n");
    }
   
    fclose(file1);
    fclose(file2);
    fclose(output_file);
   
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
   
    printf("Matrix multiplication completed successfully\n");
    printf("Result matrix dimensions: %d x %d\n", rows1, cols2);
    return 0;
}