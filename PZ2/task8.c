#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    char old_string[256];
    char new_string[256];
    FILE *input_file, *output_file;
    char line[1000];
    char *pos;
    char temp[2000];
    
    strcpy(filename, "TXT/task8.txt");
    strcpy(old_string, "Hello");
    strcpy(new_string, "Hi");
    
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    output_file = fopen("temp_file", "w");
    if (output_file == NULL) {
        printf("Error creating temp file\n");
        fclose(input_file);
        return 1;
    }
    
    while (fgets(line, sizeof(line), input_file)) {
        char *result = line;
        char *temp_line = malloc(strlen(line) * 2);
        strcpy(temp_line, line);
        
        while ((pos = strstr(result, old_string)) != NULL) {
            int len = pos - result;
            strncpy(temp, result, len);
            temp[len] = '\0';
            strcat(temp, new_string);
            strcat(temp, pos + strlen(old_string));
            strcpy(temp_line, temp);
            result = temp_line + len + strlen(new_string);
        }
        
        fputs(temp_line, output_file);
        free(temp_line);
    }
    
    fclose(input_file);
    fclose(output_file);
    
    remove(filename);
    rename("temp_file", filename);
    printf("Replacement completed\n");
    return 0;
}
