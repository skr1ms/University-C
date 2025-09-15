#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char filename[256];
    FILE *file;
    int c;
    int number = 0;
    int sign = 1;
    int in_number = 0;
    int count = 0;
    
    strcpy(filename, "TXT/task5.txt");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while ((c = fgetc(file)) != EOF) {
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
                if (in_number && number > 0 && number % 2 == 0) {
                    count++;
                }
                sign = (c == '+') ? 1 : -1;
                number = 0;
            }
        } else {
            if (in_number && number > 0 && number % 2 == 0) {
                count++;
            }
            in_number = 0;
            number = 0;
        }
    }
    
    if (in_number && number > 0 && number % 2 == 0) {
        count++;
    }
    
    fclose(file);
    printf("Number of even positive numbers: %d\n", count);
    return 0;
}
