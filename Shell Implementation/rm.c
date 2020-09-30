#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char prompt;
    if(strcmp(argv[1],"-i")==0){
        printf("Are you sure that you want to remove %s?\n(Enter Y --> yes & N --> no\n)", argv[2]);
        int ans = fgetc(stdin);
        prompt = (char) ans;
        if(prompt == 'Y'){
            remove(argv[2]);
        }
        else{
            printf("File not removed!\n");
            return 0;
        }
    }
    else if(strcmp(argv[1], "-d")==0){
        int status;
        status = rmdir(argv[2]);
        if(status == 0){
            printf("Successfully removed directory!\n");
        }
        if(status == -1){
            printf("Unsuccessful!! Directory was not removed.\n");
        }
    }
    else{
        remove(argv[1]);
        printf("File removed successfully!");
    }
    
    return 0;
}