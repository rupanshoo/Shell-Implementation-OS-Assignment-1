#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    remove(argv[1]);
    printf("File removed successfully!");
    
    return 0;
}