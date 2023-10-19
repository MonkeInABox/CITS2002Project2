#include "mysync.h"

void copyfile(struct stat *stats1, char *name1, struct stat stats2, char *name2){
    if(&stats1->st_mtime > &stats2.st_mtime){
        /*
        FILE *fp;
        fp  = fopen (name1, "w");              //write ONLY BITCHES
        fclose(fp);*/
        struct utimbuf new_times;
        new_times.actime = stats1->st_atime; /* keep atime unchanged */
        new_times.modtime = stats1->st_mtime;    /* set mtime to current time */
        utime(name1, &new_times);
        char path1[512];// = "/mnt/c/Users/jezb0/Documents/GitHub/CITS2002Project2/directory/woah!.txt";

        realpath(name1, path1);
        char path2[512];// = "/mnt/c/Users/jezb0/Documents/GitHub/CITS2002Project2/directory2/woah!.txt";
        
        realpath(name2, path2);
        //strcat(strcat(path2, "/"), name1);
        printf("%s \n", path2);
        FILE *sourceFile  = fopen(path1, "r");
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
        utime(name1, &new_times);
    }
}