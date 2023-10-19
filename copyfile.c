#include "mysync.h"

void copyfile(struct stat *stats1, char *name1, struct stat stats2, char *name2){
    if(&stats1->st_mtime > &stats2.st_mtime){
        /*
        FILE *fp;
        fp  = fopen (name1, "w");              //write ONLY BITCHES
        fclose(fp);*/
        
    }
}