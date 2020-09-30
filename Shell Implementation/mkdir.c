#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    int ch;  //to check if executed properly or not
    ch = mkdir(argv[1],0777);
    if(ch == 0){
        printf("Successfully created directory!\n");
    }
    if(ch == -1){
        printf("Unsuccessful! Directory not created.\n");
    }
    return 0;
}