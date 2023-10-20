#include "mysync.h"

void copyfile(struct stat *stats1, int index1, struct stat stats2, char *dirName2, char *fileName2){
    char *tempNames[20];
    if(&stats1->st_mtime > &stats2.st_mtime){
        for(int i = 0; i < 5; i++){
            tempNames[i] = newDir[i];
        }
        char path1[512];
        printf("%s\n",strcat(strcat(realpath(dirNames[index1], path1),"/"), newDir[index1]));
        char path2[512]; 
        printf("%s\n",strcat(strcat(realpath(dirName2, path2),"/"), fileName2));
        printf("COPY 2: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        FILE *sourceFile  = fopen(path1, "r");
        FILE *destFile    = fopen(path2, "w");  
        printf("COPY 3: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        if (sourceFile == NULL || destFile == NULL)
        {
            printf("\nUnable to open file.\n");
            exit(EXIT_FAILURE);
        }
        printf("COPY 4: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        char ch = fgetc(sourceFile);
        while (ch != EOF)
        {
            fputc(ch, destFile);
            ch = fgetc(sourceFile);
        }
        for(int i = 0; i < 5; i++){
            newDir[i] = tempNames[i];
        }
        printf("COPY 5: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        fclose(sourceFile);
        fclose(destFile);
        printf(" COPY6: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
    }
    if(&stats1->st_mtime < &stats2.st_mtime){
        for(int i = 0; i < 5; i++){
            tempNames[i] = dirName[i];
        }
        printf("COPY 1:%s %s %s \n", newDir[0], newDir[1], newDir[2]);
        char path2[512];
        char path1[512]; 
        printf("%s\n",strcat(strcat(realpath(dirName2, path1),"/"), fileName2));
        printf("%s\n",strcat(strcat(realpath(dirNames[index1], path2),"/"), newDir[index1]));
        printf("COPY 2: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        FILE *sourceFile  = fopen(path2, "r");
        FILE *destFile    = fopen(path1, "w");  
        printf("COPY 3: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        if (sourceFile == NULL || destFile == NULL)
        {
            printf("\nUnable to open file.\n");
            exit(EXIT_FAILURE);
        }
        printf("COPY 4: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        char ch = fgetc(sourceFile);
        while (ch != EOF)
        {
            fputc(ch, destFile);
            ch = fgetc(sourceFile);
        }
        for(int i = 0; i < 5; i++){
            newDir[i] = tempNames[i];
        }
        printf("COPY 5: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
        fclose(sourceFile);
        fclose(destFile);
        printf("COPY 6: %s %s %s \n", newDir[0], newDir[1], newDir[2]);
    }
}