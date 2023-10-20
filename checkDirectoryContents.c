#include "mysync.h"

//adds all missing files to both directories.
void checkDirectoryContents(){
    //all files that aren't in the first directory are added into the first directory.
    int copy = 0;
    for(int i = startIndex[0]; i < startIndex[1]; i++){
        makingNewFile(0, i);
    }
    /*all files in the first directory (besides the files that were just added),
      are compared to all the files in the second directory, if the file isn't present
      in the second directory, then the that file is created in the second directory with all
      of its contents.*/
    for(int i = 0; i < startIndex[1]; i++){
        copy = 0;
        for(int j = startIndex[0]; j < startIndex[1]; j++){
            if(strcmp(newDir[i], newDir[j]) == 0){
                copy = 1;
                break;
            }
        }
        if(copy == 0){
            makingNewFile(startIndex[0], i);
        }
    }   
}