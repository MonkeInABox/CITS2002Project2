#include mysync.h
void checkDirectoryContents(DIR* dir, char *currentDirName){
    struct dirent* dirEntry;
    for(int i; i < 100; i++){ //the i < 100 should be replaced with the size of the dirNames array.
        if(strcmp(directoryName, dirNames[i]) != 0){
            while((dirEntry = readdir(dir)) != NULL){
                if(strcmp(newDir[i], dirEntry->d_name) = 0){
                    copyfile();
                }
            }
        } else {
            makefile();
        }
    }
}