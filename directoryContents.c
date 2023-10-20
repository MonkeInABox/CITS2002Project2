#include "mysync.h"

/*This function checks through the directory parameter, storing the names, stats, paths, of the files, 
and the name of the directory each file is stored in. Each file name is also compared to every already stored file,
determining whether this file has already been stored or not, if it has, it is run through the copyfile function.
End result leaves us with what files from which directories will make up the synced directories.
*/
void directoryContents(DIR* dir, char* currentDirName){
    static int firstDir = 0;
    struct dirent* dirEntry;
    static int i = 0;
        //reads through every file in the directory.
        while((dirEntry = readdir(dir)) != NULL){
            struct stat attr;
            //gone through if -a is not specified in the command line
            if(!aflag){
                //checks if this is the first directory that is being passed through the function
                //this is so that we don't waste time trying to compare files within itself
                if(firstDir == 0){
                    //filters all files and directories that start with '.'.
                    if(dirEntry->d_name[0] != '.'){
                    newDir[i] = dirEntry->d_name;
                    stat(newDirPath[i], newDirStat[i]);
                    dirNames[i] = currentDirName;
                    i++;
                    }
                } else{ //for when this isn't the first directory that has been passed through the function
                    if(dirEntry->d_name[0] != '.'){
                        //we don't know if the current file should be put into the arrays yet, everything we
                        //need to run the file through copyfile is put into temporary variables. i.e. path and attr.
                        dirNames[i] = currentDirName;
                        char path[512];
                        int copy = 0;
                        realpath(dirEntry->d_name, path);
                        stat(path, &attr);
                        //runs through the names of every file that is currently already stored and compares
                        //them to the current file name to determine if it is a copy.
                        //the file is then copied unless it's a parent/root directory.
                        for(int k = 0; k < i; k++){
                            if(strcmp(newDir[k], dirEntry->d_name) == 0){
                                if(strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0){
                                    copyfile(newDirStat[k], k, attr, currentDirName, dirEntry->d_name); 
                                }
                                copy = 1;
                                break;
                            }
                        }
                        //if the current file isn't a copy, then all the details of the file are added as normal.
                        if(copy == 0){
                            newDir[i] = dirEntry->d_name;
                            realpath(dirEntry->d_name, newDirPath[i]);
                            stat(newDirPath[i], newDirStat[i]);
                            i++;   
                        }                   
                    }
                }
            }
            else{ //gone through if -a is specified in the command line. Does the same thing as when aflag is false except it considers files with '.' at the start of their names.
                printf("firstDir: %i \n", firstDir);
                if(firstDir == 0){
                    newDir[i] = dirEntry->d_name;
                    stat(newDirPath[i], newDirStat[i]);
                    dirNames[i] = currentDirName;
                    realpath(dirEntry->d_name,newDirPath[i]);
                    i++;
                } 
                else{
                        dirNames[i] = currentDirName;
                        char path[512];
                        int copy = 0;
                        realpath(dirEntry->d_name, path);
                        stat(path, &attr);
                        for(int k = 0; k < i; k++){
                            if(strcmp(newDir[k], dirEntry->d_name) == 0){
                                if(strcmp(newDir[k], ".") != 0 && strcmp(newDir[k], "..") != 0){
                                    copyfile(newDirStat[k], k, attr, currentDirName, dirEntry->d_name);
                                }
                                copy = 1;
                                break;
                            }
                        } 
                        if(copy == 0){
                            newDir[i] = dirEntry->d_name;
                            realpath(dirEntry->d_name, newDirPath[i]);
                            stat(newDirPath[i], newDirStat[i]);
                            i++;   
                        }
                                    
                }
            }
        }
    startIndex[firstDir] = i;
    firstDir++;
    closedir(dir);
}