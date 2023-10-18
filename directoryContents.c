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
int compareTimes(const struct timespec *t1, const struct timespec *t2) {
    if (t1->tv_sec == t2->tv_sec)
        return (t1->tv_nsec > t2->tv_nsec) - (t1->tv_nsec < t2->tv_nsec);
        //returns 0 if the two times are equal
    else
        return (t1->tv_sec > t2->tv_sec) ? 1 : -1;
        //returns 1 if t1 > t2, else -1
}

int indexesToCopy(char *fileNames1[], char *filenames2[]){
    fprintf( stdout, "%s and \n", fileNames1[i] fileNames2[]);
}  

void directoryContents(DIR* dir){
    struct dirent* dirEntry;
    //printf("ermm");
    int i = 0;
        while((dirEntry = readdir(dir)) != NULL){
            struct stat attr;
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
                char timemod[50];
                dirpath1[i] = realpath(dirEntry->d_name, NULL);
                printf("%i\n", i);
                printf("arraylength: %ld\n", sizeof(*dirpath1));
                //printf("%s\n", dirpath1[i]);
                stat(dirCopy1[i], &attr);
                strftime(timemod, 50, "%c", localtime(&(attr.st_mtime)));
                printf("Last modified time: %s\n", timemod);
                i++;
            }
        }
    closedir(dir);
}