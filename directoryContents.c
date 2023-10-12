#include "mysync.h"

/*void readFile(char fileName[]){
    FILE *compFile;
    compFile = fopen(fileName, "r");
    int line = 0;
    while(!feof(compFile) && !ferror(compFile)){
        if(fgets(fileCopy1[line], 1000, compFile) != NULL){
            line++;
        }
    }
    fclose(compFile);
}
*/
void directoryContents(DIR* dir){
    struct dirent* dirEntry;
    //printf("ermm");
    int i = 0;
        while((dirEntry = readdir(dir)) != NULL){
            printf("%s\n", dirEntry->d_name);
            dirCopy1[i] =  dirEntry->d_name;
            i++;
        }
        //printf("%s\n", dirCopy1[2]);
    closedir(dir);
}