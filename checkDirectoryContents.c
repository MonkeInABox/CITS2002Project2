#include "mysync.h"

void checkDirectoryContents(){
    int copy = 0;
    for(int i = startIndex[0]; i < startIndex[1]; i++){
        makingNewFile(0, i);
        printf("HERE5\n");
    }
    printf("HERE2\n");
    for(int i = 0; i < startIndex[1]; i++){
        for(int j = startIndex[0]; j < startIndex[1]; j++){
            printf("HERE1\n");
            if(strcmp(newDir[i], newDir[j]) == 0){
                copy = 1;
                printf("HERE3\n");
                break;
            }
        }
        if(copy == 0){
            printf("HERE4\n");
            makingNewFile(startIndex[0], i);
        }
    }   
}