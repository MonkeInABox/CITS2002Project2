#include "mysync.h"

void checkDirectoryContents(){
    int copy = 0;
    for(int i = startIndex; i < 100; i++){
        if(strcmp(newDir[i], "0") = 0){
            break;
        }
        makingNewFile(0, i);
    }
    for(int i = 0; i < startIndex; i++){
        for(int j = startIndex; j < 100, j++){
            if(strcmp(newDir[i], newDir[j]) == 0){
                copy = 1;
                break;
            }
        }
        if(copy == 0){
            makingNewFile(startIndex, i);
        }
    }   
}