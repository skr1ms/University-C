#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *file;
    int n;
    int count = 0;
    int num;
    int last1 = 0, last2 = 1, next;
    
    strcpy(filename, "TXT/task11.txt");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while (fscanf(file, "%d", &num) == 1) {
        count++;
    }
    
    fclose(file);
    
    printf("File already contains %d Fibonacci numbers\n", count);
    n = 3;
    
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        next = last1 + last2;
        fprintf(file, " %d", next);
        last1 = last2;
        last2 = next;
    }
    
    fclose(file);
    printf("Added %d Fibonacci numbers\n", n);
    return 0;
}
