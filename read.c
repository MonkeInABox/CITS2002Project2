#include "mysync.h"

char*[] readFile(char fileName[]){
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

char*[] readDir(char dirName[]){
    DIR *compDir;
    compDir = fopen(dirname);
}