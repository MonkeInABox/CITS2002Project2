#include "mysync.h"

void checkDirectoryContents(DIR* dir, char *currentDirName){
    struct dirent* dirEntry;
    for(int i; i < 100; i++){
        if(strcmp(dirNames[i], "0") == 0){
            break;
        }
        if(strcmp(currentDirName, dirNames[i]) != 0){
            while((dirEntry = readdir(dir)) != NULL){
                if(strcmp(newDir[i], dirEntry->d_name) == 0){
                    copyfile(k, i);
                }
            }
        } else {
            makingNewFile(k, i);
        }
    }
}