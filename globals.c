#include "mysync.h"

//GLOBALS INTITIALISED (some of these may not necessarily need to be global)
char *newDir[20];                          //used for comparison purposes
char *newDirPath[50];
struct stat *newDirStat[50]; 
char *fileCopy1[1];                             //used for comparison purposes
char *dirNames[100];
char *dirModified1[20];        //match up dirModified indexes w/ dirNames indexes?
char *dirModified2[20];
bool aflag = false;