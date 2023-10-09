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
    printf("ermm");
    int i = 0;
      if(strmp(dirCopy[1], NULL) == 0){
        while((dirEntry = readdir(dir)) != NULL){
        strcpy(dirCopy1[i], dirEntry->d_name);
        i++;
<<<<<<< HEAD:directoryContents.c
        printf("%s\n", dirEntry->d_name);
=======
        } 
    } else{
        while((dirEntry = readdir(dir)) != NULL){
        strcpy(dirCopy2[i], dirEntry->d_name);
        i++;
        } 
>>>>>>> a15450fe4a282ef46004145585547ed94f14b810:read.c
    }
    closedir(dir);
}