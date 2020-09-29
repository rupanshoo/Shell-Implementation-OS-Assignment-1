#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>  //for opendir()
#include <string.h>


int main(int argc, char *argv[]){
    DIR *dir;   //make a directory
    struct dirent *content;
    struct stat sMetaData;   //stores metadata of each file

    char buffer[700];  //to help get size of each file too 

    dir = opendir(".");  //to open current directory
    if(dir == NULL){
        printf("ERROR! Can't open directory\n");
        return 0;
    }

    while((content = readdir(dir)) != NULL){
        if(strcmp(argv[1],"-a")==0){    //to print hidden files too
            printf(">> %s\n", content->d_name);
        }
        else if(strcmp(argv[1], "-F") == 0){
            
            if(stat(content->d_name, &sMetaData) == -1){
                printf("Error with stat!!");
                return 0;
            }

            else{
                if(S_ISDIR(sMetaData.st_mode)){
                    if(content->d_name[0] == '.') continue;
                    printf(">> %s/\n", content->d_name);
                }
            }
        }
        else{   // normal print 
            if(content->d_name[0] == '.') continue;
            printf(">> %s\n", content->d_name);
        }
        
    }

    closedir(dir);


    return 0;
}