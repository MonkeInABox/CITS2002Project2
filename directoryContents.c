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
    //printf("ermm");
    int i = 0;
        while((dirEntry = readdir(dir)) != NULL){
            if(!aflag){
                if(dirEntry->d_name[0] != '.'){
                    printf("%s\n", dirEntry->d_name);
                    dirCopy1[i] =  dirEntry->d_name;
                    //dirpath1[i] = realpath(dirEntry->d_name, NULL);
                    //printf("%s\n", dirpath1[i]);
                    dirpath1[i] = realpath(dirEntry->d_name, NULL);
                    struct stat attrib;
                    stat(dirEntry->d_name, &attrib);
                    char time[50];
                    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&attrib.st_mtime));
                    printf ("%s\n", time);
                    i++;
                }
            }
            else{
                printf("%s\n", dirEntry->d_name);
                    dirCopy1[i] =  dirEntry->d_name;
                    //dirpath1[i] = realpath(dirEntry->d_name, NULL);
                    //printf("%s\n", dirpath1[i]);
                    dirpath1[i] = realpath(dirEntry->d_name, NULL);
                    struct stat attrib;
                    stat(dirEntry->d_name, &attrib);
                    char time[50];
                    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&attrib.st_mtime));
                    printf ("%s\n", time);
                    i++;
            }
        }
        //printf("%s\n", dirCopy1[2]);
    closedir(dir);
}