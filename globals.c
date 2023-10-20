#include "mysync.h"

//GLOBALS INTITIALISED
char *newDir[40];                          //stores the names of files that will be in the synced directories
char *newDirPath[50];                      //stores the paths to each file that will be in the synced directories
struct stat *newDirStat[50];               //stores the stats for each item that will be in the synced directories
char *fileCopy1[1];                        //used for comparison purposes, storing a copy of the file
char *dirNames[100];                       //stores directory names
bool aflag = false;                        //used to pass through whether the a command has been used
int startIndex[2];                         //used to store indexes of where the directory source of files in newDir, newDirPath, etc. arrays changes