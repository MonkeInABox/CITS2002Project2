#include "mysync.h"
//main function, this calls the rest of the program
/*
JEREMY BUTSON - 23390554
DYLAN ARTO - 23360073
*/
#define OPTLIST "ai:no:prv" //the possible commands that can be input


//usage error function
void usage(int value) {
    if (value == 1) {
        printf("please input ./mysync  [cmd]  [dir/s] \n");
        printf("--cmd options-- \n -a : all files are synchronised \n -i : filenames matching input are ingnored \n -n : files are identified, verbose output \n -o : only files matching input are synchronised \n -p : new file has same modification time and permissions \n -r : any dir in mentioned dir is processed \n -v : verbose output\n");
    }
    else if (value == 2) {
        printf("Directory does not exist\n");
    }
}

//MAIN 
int main(int argc, char *argv[]) {
    DIR* dir[argc];
    int n = 0;
    for(int i = 2; i < argc; i++){
        dir[n] = opendir(argv[i]);
        n++;
    }
    for(int i = 0; i < n; i++){
        if (dir[i]) {
            if(i == 0){
            int  opt;
                while((opt = getopt(argc, argv, OPTLIST)) != -1)   {  
                    
                    if(opt == 'a') {
                        aflag  =  !aflag;
                    }
                    else if(opt == 'i') {
                        //pattern  =  strdup(optarg);
                    }
                    else if(opt == 'n') {
                        //pattern  =  atoi(optarg);
                    }
                    //  if an option not listed is put in
                    else {
                    usage(1);
                    exit(EXIT_FAILURE);
                    }
                }
            }
            //run every directory through directory contents
            if(aflag){
                directoryContents(dir[i], argv[i+2]);
            }
            else{
                directoryContents(dir[i], argv[i+1]);
            }
    } 
    else if (ENOENT == errno) {
        //Directory does not exist. 
        usage(2);
        exit(EXIT_FAILURE);
        closedir(dir[i]);
    } 
    else {
        // opendir() failed for some other reason
        exit(EXIT_FAILURE);
        closedir(dir[i]);
    }
}
checkDirectoryContents();
exit(EXIT_SUCCESS);
}