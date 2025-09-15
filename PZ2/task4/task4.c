#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename1[256], filename2[256];
    FILE *file1, *file2;
    char line1[1000], line2[1000];
    int line_num = 1;
    int char_pos = 1;
    
    strcpy(filename1, "file1.txt");
    strcpy(filename2, "file2.txt");
    
    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");
    
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files\n");
        return 1;
    }
    
    while (fgets(line1, sizeof(line1), file1) && fgets(line2, sizeof(line2), file2)) {
        int len1 = strlen(line1);
        int len2 = strlen(line2);
        int min_len = (len1 < len2) ? len1 : len2;
        
        for (int i = 0; i < min_len; i++) {
            if (line1[i] != line2[i]) {
                printf("First difference: line %d, position %d\n", line_num, i + 1);
                fclose(file1);
                fclose(file2);
                return 0;
            }
        }
        
        if (len1 != len2) {
            printf("First difference: line %d, position %d\n", line_num, min_len + 1);
            fclose(file1);
            fclose(file2);
            return 0;
        }
        
        line_num++;
    }
    
    if (feof(file1) && feof(file2)) {
        printf("Files are identical\n");
    } else if (feof(file1)) {
        printf("First file is beginning of second\n");
    } else {
        printf("Second file is beginning of first\n");
    }
    
    fclose(file1);
    fclose(file2);
    return 0;
}
