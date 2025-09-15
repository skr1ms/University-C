#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename1[256], filename2[256];
    FILE *file1, *file2, *temp_file;
    int c;
    
    strcpy(filename1, "file1.txt");
    strcpy(filename2, "file2.txt");
    
    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
    
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files\n");
        return 1;
    }
    
    temp_file = fopen("temp_swap", "w");
    if (temp_file == NULL) {
        printf("Error creating temp file\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }
    
    while ((c = fgetc(file1)) != EOF) {
        fputc(c, temp_file);
    }
    
    fclose(file1);
    fclose(temp_file);
    
    file1 = fopen(filename1, "w");
    if (file1 == NULL) {
        printf("Error opening first file for writing\n");
        fclose(file2);
        return 1;
    }
    
    while ((c = fgetc(file2)) != EOF) {
        fputc(c, file1);
    }
    
    fclose(file1);
    fclose(file2);
    
    file2 = fopen(filename2, "w");
    temp_file = fopen("temp_swap", "r");
    
    if (file2 == NULL || temp_file == NULL) {
        printf("Error opening files for writing\n");
        return 1;
    }
    
    while ((c = fgetc(temp_file)) != EOF) {
        fputc(c, file2);
    }
    
    fclose(file2);
    fclose(temp_file);
    remove("temp_swap");
    
    printf("File contents swapped\n");
    return 0;
}
