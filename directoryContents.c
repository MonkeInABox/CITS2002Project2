#include "mysync.h"
void directoryContents(DIR* dir, char* currentDirName){
    static int firstDir = 0;
    struct dirent* dirEntry;
    static int i = 0;
    struct stat attr;
        while((dirEntry = readdir(dir)) != NULL){
            if(!aflag){
                if(firstDir == 0){
                    if(dirEntry->d_name[0] != '.'){
                    newDir[i] = dirEntry->d_name;
                    stat(newDirPath[i], &attr);
                    newDirStat[i] = &attr;
                    dirNames[i] = currentDirName;
                    i++;
                    }
                } else{
                    if(dirEntry->d_name[0] != '.'){
                        char path[512];
                        int copy = 0;
                        realpath(dirEntry->d_name, path);
                        stat(path, &attr);
                        for(int k = 0; k < i; k++){
                            if(strcmp(newDir[k], dirEntry->d_name) == 0){
                                if(strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0){
                                    copyfile(newDirStat[k], dirEntry->d_name, attr, dirEntry->d_name);  
                                }
                                copy = 1;
                                break;
                            }
                        } 
                        if(copy == 0){
                            printf("%s\n", dirEntry->d_name);
                            newDir[i] = dirEntry->d_name;
                            newDirPath[i] = realpath(dirEntry->d_name, newDirPath[i]);
                            dirNames[i] = currentDirName;
                            printf("%s \n",realpath(dirEntry->d_name, newDirPath[i]));
                            stat(newDirPath[i], &attr);
                            newDirStat[i] = &attr;
                            time_t t1 = newDirStat[i]->st_mtime;
                            printf("Last modified time: %ld \n", t1);
                            i++;   
                        }                   
                    }
                }
            }
            else{
                printf("firstDir: %i \n", firstDir);
                if(firstDir == 0){
                    newDir[i] = dirEntry->d_name;
                    stat(newDirPath[i], &attr);
                    newDirStat[i] = &attr;
                    dirNames[i] = currentDirName;
                    i++;
                } else{
                        char path[512];
                        int copy = 0;
                        realpath(dirEntry->d_name, path);
                        stat(path, &attr);
                        for(int k = 0; k < i; k++){
                            if(strcmp(newDir[k], dirEntry->d_name) == 0){
                                if(strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0){
                                    copyfile(newDirStat[k], dirEntry->d_name, attr, dirEntry->d_name);  
                                }
                                copy = 1;
                                break;
                            }
                        } 
                        if(copy == 0){
                            printf("%s\n", dirEntry->d_name);
                            newDir[i] = dirEntry->d_name;
                            newDirPath[i] = realpath(dirEntry->d_name, newDirPath[i]);
                            dirNames[i] = currentDirName;
                            printf("%s \n",realpath(dirEntry->d_name, newDirPath[i]));
                            stat(newDirPath[i], &attr);
                            newDirStat[i] = &attr;
                            time_t t1 = newDirStat[i]->st_mtime;
                            printf("Last modified time: %ld \n", t1);
                            i++;   
                        }             
                }
            }
        }
    for(int j = 0; j < i; j++){
        printf("newDir: %s \n", newDir[j]);
        printf("Dir: %s\n", dirNames[j]);
    }
    firstDir = 1;
    closedir(dir);
}