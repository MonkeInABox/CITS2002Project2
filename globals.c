#include "mysync.h"

//GLOBALS INTITIALISED (some of these may not necessarily need to be global)
char *dirCopy1[1000];                          //used for comparison purposes
char *dirCopy2[1000];                          //used for comparison purposes
char *fileCopy1[100000];                             //used for comparison purposes
char *fileCopy2[100000];                          //used for comparison purposes
char *dirNames[1000];
char *dirModified[1000];        //match up dirModified indexes w/ dirNames indexes?