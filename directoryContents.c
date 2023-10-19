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


//function to compare times
/*
int compareTimes(const struct timespec *t1, const struct timespec *t2) {
    if (t1->tv_sec == t2->tv_sec)
        return (t1->tv_nsec > t2->tv_nsec) - (t1->tv_nsec < t2->tv_nsec);
        //returns 0 if the two times are equal
    else
        return (t1->tv_sec > t2->tv_sec) ? 1 : -1;
        //returns 1 if t1 > t2, else -1
}
*/

void indexesToCopy(char *fileNames1[], char *filenames2[]){
    //fprintf( stdout, "%s and \n", fileNames1[] fileNames2[]);
}  

void directoryContents(DIR* dir){
    static int firstDir = 0;
    struct dirent* dirEntry;
    //printf("ermm");
    static int i = 0;
    struct stat attr;
        while((dirEntry = readdir(dir)) != NULL){
            if(!aflag){
                if(firstDir == 0){
                    if(dirEntry->d_name[0] != '.'){
                        printf("%s\n", dirEntry->d_name);
                        printf("poop");
                        newDir[i] = dirEntry->d_name;
                        newDirPath[i] = realpath(dirEntry->d_name, newDirPath[i]);
                        printf("%s \n",realpath(dirEntry->d_name, newDirPath[i]));
                        stat(newDirPath[i], &attr);
                        newDirStat[i] = &attr;
                        time_t t1 = newDirStat[i]->st_mtime;
                        printf("Last modified time: %ld \n", t1);
                        i++;
                    }
                } else{
                        int copy = 0;
                        char *path = realpath(dirEntry->d_name, NULL);
                        stat(path, &attr);
                        //checks if the current directory/file (i actually dont know if this work with files, it probs doesnt),
                        //has already appeared before. If so, the date modified dates of both are checked, and if the current
                        //directory/file is more recent, then its path and stat replaces the other directory/file's path and stat's place.
                        //if no copy is found, then it is added to the newDir as normal.
                        for(int k = 0; k < i; k++){
                            if(strcmp(newDir[k], dirEntry->d_name) == 0){
                                if(&newDirStat[k]->st_mtime < &attr.st_mtime){
                                    newDirPath[k] = path;
                                    newDirStat[k] = &attr;
                                }
                                copy = 1;
                            }
                        }
                        if(copy == 0){
                            printf("%s\n", dirEntry->d_name);
                            newDir[i] = dirEntry->d_name;
                            newDirPath[i] = realpath(dirEntry->d_name, newDirPath[i]);
                            printf("%s \n",realpath(dirEntry->d_name, newDirPath[i]));
                            stat(newDirPath[i], &attr);
                            newDirStat[i] = &attr;
                            time_t t1 = newDirStat[i]->st_mtime;
                            printf("Last modified time: %ld \n", t1);
                            i++;   
                        }
                                        
                    }
            }
            else{
                printf("firstDir: %i \n", firstDir);
                if(firstDir == 0){
                    char *name = dirEntry->d_name;
                    printf("%s\n", name);
                    newDir[i] = name;
                    printf("%s \n",realpath(dirEntry->d_name, newDirPath[i]));
                    stat(newDirPath[i], &attr);
                    newDirStat[i] = &attr;
                    time_t t1 = newDirStat[i]->st_mtime;
                    printf("Last modified time: %ld \n", t1);
                    i++;
                } else{
                        int copy = 0;
                        char *path = realpath(dirEntry->d_name, newDirPath[i]);  
                        stat(path, &attr);
                        printf("%s \n", path);
                        for(int k = 0; k < i; k++){
                            printf("Compare: %s \n", newDir[k]);
                            printf("Current: %s \n", dirEntry->d_name);   
                            printf("%i \n", strcmp(newDir[k], dirEntry->d_name));
                            if(strcmp(newDir[k], dirEntry->d_name) == 0){
                                if(&newDirStat[k]->st_mtime < &attr.st_mtime){
                                    newDirPath[k] = path;
                                    newDirStat[k] = &attr;
                                }
                                copy = 1;
                                break;
                            }
                        } 
                        if(copy == 0){
                            printf("%s\n", dirEntry->d_name);
                            newDir[i] = dirEntry->d_name;
                            newDirPath[i] = realpath(dirEntry->d_name, newDirPath[i]);
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
    }
    firstDir = 1;
    closedir(dir);
}                

/*                printf("%s\n", dirEntry->d_name);
                newDir[i] = dirEntry->d_name;
                char timemod[50];
                newDirPath[i] = realpath(dirEntry->d_name, NULL);
                printf("%i\n", i);
                printf("arraylength: %ld\n", sizeof(*newDirPath));
                //printf("%s\n", newDirPath[i]);
                stat(newDir[i], &attr);
                strftime(timemod, 50, "%c", localtime(&(attr.st_mtime)));
                printf("Last modified time: %s\n", timemod);
                i++; */