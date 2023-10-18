#include "mysync.h"

#define OPTLIST "ai:no:prv"

void usage(int value) {
    if (value == 1) {
        printf("please input ./mysync  [cmd]  [dir/s] \n");
        printf("--cmd options-- \n -a : all files are synchronised \n -i : filenames matching input are ingnored \n -n : files are identified, verbose output \n -o : only files matching input are synchronised \n -p : new file has same modification time and permissions \n -r : any dir in mentioned dir is processed \n -v : verbose output");
    }
    else if (value == 2) {
        printf("Directory does not exist");
    }
}

int main(int argc, char *argv[]) {
    DIR* dir[argc];
    int n = 0;
    for(int i = 2; i < argc; i++){
        dir[n] = opendir(argv[i]);
        n++;
    }
    //printf("awesome \n");
    for(int i = 0; i < n; i++){
        if (dir[i]) {
            printf("awesomeSauce");
            //directoryContents(dir);
            //Directory exists. 
            if(i == 0){
                //printf("poop");
            int  opt;
            //char *pattern = NULL;

            //int optind	= 0;
                while((opt = getopt(argc, argv, OPTLIST)) != -1)   {  
                //  ACCEPT A BOOLEAN ARGUMENT
                    if(opt == 'a') {
                        //printf("poop");
                        aflag  =  !aflag;
                        //printf("%i", aflag);
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
                    usage(1);
                    }
                }
            }
            //printf("poop");
            directoryContents(dir[i]);
            
            //argc  -= optind;
            //argv  += optind;
            //exit(EXIT_SUCCESS); 
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
exit(EXIT_SUCCESS);
}