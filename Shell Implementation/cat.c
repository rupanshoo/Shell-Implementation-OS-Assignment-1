#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define Buffer_Size 1000

int main(int argc, char* argv[]){

    if(argv[1][0] == '>'){
        char *token = strtok(argv[1],">");
        char* newFileName = token;
        char writeInNewFile[Buffer_Size];


        FILE* pt;
        pt = fopen(newFileName, "w");
        if(pt == NULL){
            printf("Unable to open file.\n");
            return 0;
        }
        else{
            printf("Successfully created file!\nEnter contents to be added to file: \n");
            fgets(writeInNewFile, Buffer_Size, stdin);
            fputs(writeInNewFile, pt);
        }

        fclose(pt);
    }

    else if(strcmp(argv[1], "-n") == 0){
        FILE* fileptr;
        int lineCount = 1; //line counter
        char file[Buffer_Size];
        int chr, last = 0;

        fileptr = fopen(argv[2], "r");

        if(fileptr==NULL){
                printf("Unable to open file.\n");
                return 0;
        }

        printf("%d",lineCount++);  //for line 1
        

        while((chr = getc(fileptr))!= EOF){
            if(last)
                putchar(last);
            if(last == '\n')
                printf("%d",lineCount++);
            last = chr;
        }

        putchar(last);

        if(last != '\n')
            putchar('\n');
            
        if(fileptr!=stdin)
            fclose(fileptr);
        
        return 0;
    }

    else{

        int argvCnt = 1;

        while(argv[argvCnt] != NULL){
            FILE* p;
            char file_contents[Buffer_Size];
            int totalRead =0;

            p = fopen(argv[argvCnt], "r");  //open in read mode

            if(p==NULL){
                printf("Unable to open file.\n");
                return 0;
            }

            while (fgets(file_contents, Buffer_Size,p)!= NULL)
            {
                totalRead = strlen(file_contents);

                if(file_contents[totalRead-1] == '\n'){
                    file_contents[totalRead-1] = '\0';
                }

                //file_contents[totalRead-1] = file_contents[totalRead-1] == '\n' ? '\0' : file_contents[totalRead-1];  -- shorter for above if condn
                printf("%s\n", file_contents);
            }

            fclose(p);

            argvCnt ++;
        }
    }
    
    //printf("in cat");
    return 0;
} 