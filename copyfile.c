#include "mysync.h"

void copyfile(struct stat *stats1, char *name1, struct stat stats2, char *name2){
    if(&stats1->st_mtime > &stats2.st_mtime){
        struct utimbuf new_times;
        //printf("wojahusdjh");
        char path[512];
        realpath(name1, path);
        new_times.actime = stats2.st_atime;
        new_times.modtime = stats2.st_mtime;
        chdir(path);
        FILE *fp;
        fp = fopen((strcat(path, "/"), name2), "rw");
        utime(name2, &new_times);
        printf("CLOSE");
        fclose (fp);
    }
}