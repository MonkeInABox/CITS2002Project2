#include "mysync.h"

//GLOBALS INTITIALISED (some of these may not necessarily need to be global)
char *dirCopy1[/* max files in dir */];                          //used for comparison purposes
char *dirCopy2[/* max files in dir */];                          //used for comparison purposes
char *fileCopy1[/* max file size */];                             //used for comparison purposes
char *fileCopy2[/* max files in size */];                          //used for comparison purposes
char *dirNames[/* no. diretories */];
char *dirModified[/* no. files? or no. directories? */];        //match up dirModified indexes w/ dirNames indexes?