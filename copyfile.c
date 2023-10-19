#include "mysync.h"

void copyfile(struct stat *stats1, char *name1, struct stat stats2, char *name2){
    if(&stats1->st_mtime > &stats2.st_mtime){
        /*
        FILE *fp;
        fp  = fopen (name1, "w");              //write ONLY BITCHES
        fclose(fp);*/
        struct utimbuf new_times;
        new_times.actime = stats1->st_atime; /* keep atime unchanged */
        new_times.modtime = time(NULL);    /* set mtime to current time */
        utime(name1, &new_times);
    }
}