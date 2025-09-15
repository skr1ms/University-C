#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename1[256], filename2[256], filename3[256];
    FILE *file1, *file2, *file3;
    long size1, size2, size3;
    int c;
    
    strcpy(filename1, "short.txt");
    strcpy(filename2, "medium.txt");
    strcpy(filename3, "long.txt");
    
    file1 = fopen(filename1, "rb");
    file2 = fopen(filename2, "rb");
    file3 = fopen(filename3, "rb");
    
    if (file1 == NULL || file2 == NULL || file3 == NULL) {
        printf("Error opening files\n");
        return 1;
    }
    
    fseek(file1, 0, SEEK_END);
    size1 = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    
    fseek(file2, 0, SEEK_END);
    size2 = ftell(file2);
    fseek(file2, 0, SEEK_SET);
    
    fseek(file3, 0, SEEK_END);
    size3 = ftell(file3);
    fseek(file3, 0, SEEK_SET);
    
    char *longest_file, *shortest_file;
    long longest_size, shortest_size;
    
    if (size1 >= size2 && size1 >= size3) {
        longest_file = filename1;
        longest_size = size1;
        if (size2 <= size3) {
            shortest_file = filename2;
            shortest_size = size2;
        } else {
            shortest_file = filename3;
            shortest_size = size3;
        }
    } else if (size2 >= size3) {
        longest_file = filename2;
        longest_size = size2;
        if (size1 <= size3) {
            shortest_file = filename1;
            shortest_size = size1;
        } else {
            shortest_file = filename3;
            shortest_size = size3;
        }
    } else {
        longest_file = filename3;
        longest_size = size3;
        if (size1 <= size2) {
            shortest_file = filename1;
            shortest_size = size1;
        } else {
            shortest_file = filename2;
            shortest_size = size2;
        }
    }
    
    fclose(file1);
    fclose(file2);
    fclose(file3);
    
    FILE *shortest = fopen(shortest_file, "r");
    FILE *longest = fopen(longest_file, "w");
    
    if (shortest == NULL || longest == NULL) {
        printf("Error opening files for copying\n");
        return 1;
    }
    
    while ((c = fgetc(shortest)) != EOF) {
        fputc(c, longest);
    }
    
    fclose(shortest);
    fclose(longest);
    
    printf("Content of %s replaced with content of %s\n", longest_file, shortest_file);
    return 0;
}
