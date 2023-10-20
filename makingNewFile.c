#include "mysync.h"

//creates a file into a directory, copying the contents into that file from a certain
//file source.
void makingNewFile(int index1, int index2) {
    //the file is created and the file whose contents are to be copied over is opened
    char path2[512]; 
    strcat(strcat(realpath(dirNames[index2], path2),"/"), newDir[index2]);
    FILE *sourceFile  = fopen(path2, "r");
    chdir(dirNames[index1]);
    fopen(newDir[index2], "w");
    char path1[512];
    strcat(strcat(realpath(dirNames[index1], path1),"/"), newDir[index2]);
    FILE *destFile = fopen(path1, "w");  
    //checks if creating and opening the files is successful
    if (sourceFile == NULL || destFile == NULL){
        printf("\nUnable to open file.\n");
        exit(EXIT_FAILURE);
    }
    //copies the file contents
    char ch = fgetc(sourceFile);
    while (ch != EOF)
    {
        fputc(ch, destFile);
        ch = fgetc(sourceFile);
    }
    //closes the files
    fclose(sourceFile);
    fclose(destFile);
}
