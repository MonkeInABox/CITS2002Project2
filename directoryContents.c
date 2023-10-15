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
    struct stat attr;
    //printf("ermm");
    int i = 0;
        while((dirEntry = readdir(dir)) != NULL){
            if(!aflag){
                if(dirEntry->d_name[0] != '.'){
                    printf("%s\n", dirEntry->d_name);
                    dirCopy1[i] = dirEntry->d_name;
                    //dirpath1[i] = realpath(dirEntry->d_name, NULL);
                    //printf("%s\n", dirpath1[i]);
                    dirpath1[i] = realpath(dirEntry->d_name, NULL);
                    stat(dirpath1[i], &attr);
                    printf("Last modified time: %s", ctime(&attr.st_mtime));
                    i++;
                }
            }
            else{
                printf("%s\n", dirEntry->d_name);
                dirCopy1[i] = dirEntry->d_name;
                //dirpath1[i] = realpath(dirEntry->d_name, NULL);
                //printf("%s\n", dirpath1[i]);
                dirpath1[i] = realpath(dirEntry->d_name, NULL);
                stat(dirpath1[i], &attr);
                printf("Last modified time: %s", ctime(&attr.st_mtime));
                i++;
            }
        }
        //printf("%s\n", dirCopy1[2]);
    closedir(dir);
}