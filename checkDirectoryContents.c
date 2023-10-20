#include "mysync.h"

void checkDirectoryContents(){
    int copy = 0;
    for(int i = startIndex[0]; i < startIndex[1]; i++){
        makingNewFile(0, i);
    }
    for(int i = 0; i < startIndex[0]; i++){
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