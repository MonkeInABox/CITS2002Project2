#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define _POSIX_C_SOURCE 2
#include <getopt.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
//GLOBAL PROCESSOR CONSTANTS


//GLOBAL FUNCTIONS
extern void mysync();
extern void directoryContents(DIR* dir);

//GLOBAL VARIABLES DECLARED (see globals.c for comments about the variables)
extern char *dirNames[];
extern char *dirModified[];
extern char *dirCopy1[];
extern char *dirCopy2[];
extern char *fileCopy1[];
extern char *fileCopy2[];
