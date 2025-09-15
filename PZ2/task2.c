#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *file;
    int freq[256] = {0};
    int c;
    int max_freq = 0;
    char most_frequent = 0;
    
    strcpy(filename, "TXT/task2.txt");
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    while ((c = fgetc(file)) != EOF) {
        freq[c]++;
        if (freq[c] > max_freq) {
            max_freq = freq[c];
            most_frequent = c;
        }
    }
    
    fclose(file);
    
    printf("Most frequent character: '%c' (appears %d times)\n", most_frequent, max_freq);
    return 0;
}
