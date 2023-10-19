#include "mysync.h"

void makingNewFile(int index1, int index2) {
    char path1[512];
    strcat(strcat(realpath(dirNames[index1], path1),"/"), newDir[index2]);
    char path2[512]; 
    strcat(strcat(realpath(dirNames[index2], path2),"/"), newDir[index2]);
    FILE *sourceFile  = fopen(path2, "r");
    FILE *destFile    = fopen(path1, "w");  

    if (sourceFile == NULL || destFile == NULL){
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }
    char ch = fgetc(sourceFile);
    while (ch != EOF)
    {
        fputc(ch, destFile);
        ch = fgetc(sourceFile);
    }
    fclose(sourceFile);
    fclose(destFile);
}
