#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//#define _POSIX_C_SOURCE 2
#include <getopt.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
//GLOBAL PROCESSOR CONSTANTS


//GLOBAL FUNCTIONS
extern void mysync();
extern void directoryContents(DIR* dir, char* currentDirName);
extern void copyfile(struct stat *stats1, int index1, struct stat stats2, char *dirName2, char *fileName2);
extern void makingNewFile(int index1, int index2);
extern void checkDirectoryContents(DIR* dir, char *currentDirName);

//GLOBAL VARIABLES DECLARED (see globals.c for comments about the variables)
extern char *dirNames[];
extern char *dirModified[];
extern char *newDir[];
extern char *newDirPath[];
extern struct stat *newDirStat[]; 
extern char *fileCopy1[];
extern char *fileCopy2[];
extern bool aflag;
extern bool nflag;
extern bool rflag;
extern bool pflag;
extern bool vflag;