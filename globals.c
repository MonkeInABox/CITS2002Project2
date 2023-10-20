#include "mysync.h"

//GLOBALS INTITIALISED (some of these may not necessarily need to be global)
char *newDir[40];                          //used for comparison purposes, storing the items in the directory
char *newDirPath[50];                      //stores the paths to each item in the directory
struct stat *newDirStat[50];               //stores the stats for each item in the directory
char *fileCopy1[1];                        //used for comparison purposes, storing a copy of the file
char *dirNames[100];                       //stores directory names
char *dirModified1[20];                    //
char *dirModified2[20];                    //
bool aflag = false;                        //used to pass through whether the a command has been used