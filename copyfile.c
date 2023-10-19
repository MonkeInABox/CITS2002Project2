#include "mysync.h"

void copyfile(struct stat *stats1, int index1, struct stat stats2, int index2){
    if(&stats1->st_mtime > &stats2.st_mtime){
        /*
        FILE *fp;
        fp  = fopen (name1, "w");              //write ONLY BITCHES
        fclose(fp);*/
        //struct utimbuf new_times;
        //new_times.actime = stats1->st_atime; /* keep atime unchanged */
        //new_times.modtime = stats1->st_mtime;    /* set mtime to current time */
        //printf("dsfghjklballs\n");
        //utime(strcat(strcat(realpath(dirNames[index1], NULL),"/"),newDir[index1]), &new_times);
        //printf("dsfghjklballs\n");
        //printf("%s \n", strcat(strcat(realpath(dirNames[index1], NULL),"/"), newDir[index1]));
        //printf("dsfghjklballs\n");
        //printf("%s \n", strcat(strcat(realpath(dirNames[index2], NULL),"/"), newDir[index2]));
        //printf("dsfghjklballs\n");
        char path1[512] =strcat(strcat(realpath(dirNames[index1], NULL),"/"), newDir[index1]);
        printf("%s\n",strcat(strcat(realpath(dirNames[index1], NULL),"/"), newDir[index1]));
        //printf("dsfghjklballs\n");
        char path2[512] =strcat(strcat(realpath(dirNames[index2], NULL),"/"), newDir[index1]); 
        //printf("dsfghjklballs\n");
        //printf("%i\n", index2);
        printf("%s\n",strcat(strcat(realpath(dirNames[index2], NULL),"/"), newDir[index2]));
        //printf("dsfghjklballs\n");
        //printf("djunkelsgkogs\n");
        FILE *sourceFile  = fopen(path1, "r");
        //printf("dsfghjklballs\n");
        //printf("dsfghjklballs\n");
        FILE *destFile    = fopen(path2, "w");  

        /* fopen() return NULL if unable to open file in given mode. */
        if (sourceFile == NULL || destFile == NULL)
        {
            /* Unable to open file hence exit */
            printf("\nUnable to open file.\n");
            printf("Please check if file exists and you have read/write privilege.\n");

            exit(EXIT_FAILURE);
        }


        /*
        * Copy file contents character by character.
        */
        char ch = fgetc(sourceFile);
        while (ch != EOF)
        {
            /* Write to destination file */
            fputc(ch, destFile);

            /* Read next character from source file */
            ch = fgetc(sourceFile);
        }


        printf("\nFiles copied successfully.\n");


        /* Finally close files to release resources */
        fclose(sourceFile);
        fclose(destFile);
    }
    if(&stats1->st_mtime < &stats2.st_mtime){
        /*
        FILE *fp;
        fp  = fopen (name1, "w");              //write ONLY BITCHES
        fclose(fp);*/
        struct utimbuf new_times;
        new_times.actime = stats2.st_atime; /* keep atime unchanged */
        new_times.modtime = stats2.st_mtime;    /* set mtime to current time */
        utime(newDir[index1], &new_times);
    }
}