#include "mysync.h"

void readFile(char fileName[]){
    FILE *compFile;
    compFile = fopen(fileName, "r");
    int line = 0;
    while(!feof(compFile) && !ferror(compFile)){
        if(fgets(fileCopy1[line], 1000, compFile) != NULL){
            line++;
        }
    }
    fclose(compFile);
    return fileCopy1;
}

void readDir(char dirName[]){
    struct dirent* dirEntry;
    DIR* dir = opendir(dirName);
    int i = 0;
    while((de = readdir(dir)) != NULL){
        strcpy(dirCopy1[i], dirEntry->d_name);
        i++;
    }
    closedir(dir);
}