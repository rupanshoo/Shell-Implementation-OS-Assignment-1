#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    int ch;  //to check if executed properly or not
    if(strcmp(argv[1], "-m777") == 0){   // to set read-write-execute permissions to all users
        ch = mkdir(argv[2],0777);
        if(ch == 0){
            printf("Successfully created directory!\n");
        }
        if(ch == -1){
            printf("Unsuccessful! Directory not created.\n");
        }
    }

    else if(strcmp(argv[1], "-v") == 0){
        int paraCnt = 2;
        while(argv[paraCnt] != NULL){
            ch = mkdir(argv[paraCnt],0777);
            if(ch == 0){
                printf("Successfully created directory!%s\n", argv[paraCnt]);
            }
            if(ch == -1){
                printf("Unsuccessful! Directory %s not created.\n", argv[paraCnt]);
            }
            paraCnt++;
        }

    }

    else{
        ch = mkdir(argv[1],0777);
        if(ch == 0){
            printf("Successfully created directory!\n");
        }
        if(ch == -1){
            printf("Unsuccessful! Directory not created.\n");
        }
    }
    return 0;
}