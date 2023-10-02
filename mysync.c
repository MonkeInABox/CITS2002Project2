#include "mysync.h"

#define OPTLIST "ai:no:prv"

void usage(int value){
    if (value == 1) {
        printf("please input ./mysync  [cmd]  [dir/s] \n");
        printf("--cmd options-- \n -a : all files are synchronised \n -i : filenames matching input are ingnored \n -n : files are identified, verbose output \n -o : only files matching input are synchronised \n -p : new file has same modification time and permissions \n -r : any dir in mentioned dir is processed \n -v : verbose output");
    }
}

int main(int argc, char *argv[]) {
    int  opt;
    bool aflag   = false;
    //char *pattern = NULL;

    int optind	= 0;
    while((opt = getopt(argc, argv, OPTLIST)) != -1)   {  
//  ACCEPT A BOOLEAN ARGUMENT
	if(opt == 'a') {
            aflag  =  !aflag;
        }
//  ACCEPT A STRING ARGUMENT
	else if(opt == 'i') {
            //pattern  =  strdup(optarg);
        }
//  ACCEPT A INTEGER ARGUMENT
	else if(opt == 'n') {
            //pattern  =  atoi(optarg);
        }
//  OOPS - AN UNKNOWN ARGUMENT
        else {
            argc = -1;
        }
    }

    if(argc <= 0) {    //  display program's usage/help   
        usage(1);
    }
    argc  -= optind;
    argv  += optind;
    exit(EXIT_SUCCESS);
}