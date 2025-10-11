#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/*
Задание
Пройти по каталогу с использованием рекурсий, по всем включенным в него подкаталогам, и
посчитать сколько в них
1. каталогов;
2. пустых каталогов;
3. каталогов, содержащих только каталоги( не включая содержимого подкаталогов;
4. файлов;
5. файлов, размером меньше 100 b и с символом “t” в названии;
6. файлов, размером больше 1Kb и название начинается с символа “P”;
7. файлов, размером меньше 100 Kb и с расширением “txt”.
Для выполнения задания скачайте предложенный каталог, сохраните его на диск и
используйте для обработки каталога.
*/

typedef struct {
    int totalDirs;
    int emptyDirs;
    int dirsWithOnlyDirs;
    int totalFiles;
    int filesLt100bWithT;
    int filesGt1kbStartsP;
    int filesLt100kbTxt;
} Stats;

int hasCharInName(const char* name, char c) {
    while (*name) {
        if (*name == c) {
            return 1;
        }
        name++;
    }
    return 0;
}

int endsWith(const char* name, const char* ext) {
    size_t nameLen = strlen(name);
    size_t extLen = strlen(ext);
    
    if (nameLen < extLen) {
        return 0;
    }
    
    return strcmp(name + nameLen - extLen, ext) == 0;
}

void traverseDirectory(const char* path, Stats* stats) {
    DIR* dir;
    struct dirent* entry;
    struct stat statBuf;
    char fullPath[1024];
    int hasFiles = 0;
    int hasDirs = 0;
    int entryCount = 0;
    
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        entryCount++;
        
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        
        if (stat(fullPath, &statBuf) == -1) {
            perror("stat");
            continue;
        }
        
        if (S_ISDIR(statBuf.st_mode)) {
            hasDirs = 1;
            stats->totalDirs++;
            traverseDirectory(fullPath, stats);
        } else if (S_ISREG(statBuf.st_mode)) {
            hasFiles = 1;
            stats->totalFiles++;
            
            if (statBuf.st_size < 100 && hasCharInName(entry->d_name, 't')) {
                stats->filesLt100bWithT++;
            }
            
            if (statBuf.st_size > 1024 && entry->d_name[0] == 'P') {
                stats->filesGt1kbStartsP++;
            }
            
            if (statBuf.st_size < 102400 && endsWith(entry->d_name, ".txt")) {
                stats->filesLt100kbTxt++;
            }
        }
    }
    
    closedir(dir);
    
    if (entryCount == 0) {
        stats->emptyDirs++;
    }
    
    if (hasDirs && !hasFiles) {
        stats->dirsWithOnlyDirs++;
    }
}

int main(void) {
    Stats stats = {0};
    const char* rootDir = "Primates";
    struct stat statBuf;
    
    if (stat(rootDir, &statBuf) == -1) {
        perror("stat");
        fprintf(stderr, "Directory %s not found.\n", rootDir);
        return 1;
    }
    
    if (!S_ISDIR(statBuf.st_mode)) {
        fprintf(stderr, "%s is not a directory.\n", rootDir);
        return 1;
    }
    
    stats.totalDirs = 1;
    traverseDirectory(rootDir, &stats);
    
    printf("Statistics for directory '%s':\n", rootDir);
    printf("1. Total directories: %d\n", stats.totalDirs);
    printf("2. Empty directories: %d\n", stats.emptyDirs);
    printf("3. Directories with only directories: %d\n", stats.dirsWithOnlyDirs);
    printf("4. Total files: %d\n", stats.totalFiles);
    printf("5. Files < 100 bytes with 't' in name: %d\n", stats.filesLt100bWithT);
    printf("6. Files > 1KB starting with 'P': %d\n", stats.filesGt1kbStartsP);
    printf("7. Files < 100KB with .txt extension: %d\n", stats.filesLt100kbTxt);
    
    return 0;
}
