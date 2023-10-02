#include "mysync.h"

char*[] readFile(FILE *f){
    FILE *compFile;
    compFile = fopen(f, "r");
    int line = 0;
    while(!feof(compFile) && !ferror(compFile)){
        if(fgets(fileCopy1[line], 1000, compFile) != NULL){
            line++;
        }
    }
    fclose(compFile);
    return fileCopy1;
}