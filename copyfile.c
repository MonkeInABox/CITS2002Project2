#include "mysync.h"

void copyfile(struct stat *stats1, int index1, struct stat stats2, int index2){
    if(&stats1->st_mtime > &stats2.st_mtime){
        char path1[512];
        printf("%s\n",strcat(strcat(realpath(dirNames[index1], path1),"/"), newDir[index1]));
        char path2[512]; 
        printf("%s\n",strcat(strcat(realpath(dirNames[index2], path2),"/"), newDir[index2]));
        FILE *sourceFile  = fopen(path1, "r");
        FILE *destFile    = fopen(path2, "w");  

        if (sourceFile == NULL || destFile == NULL)
        {
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
    if(&stats1->st_mtime < &stats2.st_mtime){
        stat(realpath(newDir[index1],newDirPath[index1]), stats[index1]); 
        dirNames[index1] = dirNames[index2];
        char path2[512];
        printf("%s\n",strcat(strcat(realpath(dirNames[index2], path2),"/"), newDir[index2]));
        char path1[512]; 
        printf("%s\n",strcat(strcat(realpath(dirNames[index1], path1),"/"), newDir[index1]));
        FILE *sourceFile  = fopen(path2, "r");
        FILE *destFile    = fopen(path1, "w");  

        if (sourceFile == NULL || destFile == NULL)
        {
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
}