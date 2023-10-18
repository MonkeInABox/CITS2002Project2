#include "mysync.h"

//GLOBALS INTITIALISED (some of these may not necessarily need to be global)
char *dirCopy1[20];                          //used for comparison purposes
char *dirPath1[50];
struct stat *dirStat[50]; 
char *dirCopy2[20];                          //used for comparison purposes
char *dirPath2[20]
char *fileCopy1[1];                             //used for comparison purposes
char *dirNames[5];
char *dirModified1[20];        //match up dirModified indexes w/ dirNames indexes?
char *dirModified2[20];
bool aflag = false;