#include <stdio.h>
#include <unistd.h>   //for fork()
#include <fcntl.h>
#include <stdlib.h>  //for exit
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){
    int ret;
    ret = fork();
    int fd = open("csv-os.csv", O_RDONLY);   //opening the file in read-only mode

    int stat;

    if(fd != -1){

        if(ret > 0){    //parent process
            waitpid(ret, &stat, 0);
            if (WIFSIGNALED(stat)){
                printf("Error\n");
            }
            else if (WEXITSTATUS(stat)) {
                printf("Exited Normally\n");
            }
            printf("Parent: %d\n", getpid());

            char entry[6800];
            char delim[] = ",\n\r";
            read(fd, entry, sizeof(entry));
            char* ptr;
            int chA = 'B';

            ptr = strchr(entry, chA);
            //printf("%s\n", entry);
            //printf("%c \n", (char)entry[33]);
            char *token = strtok(entry, delim);
            char arr[400][6][3];
            int i=0;
            while(token!=NULL){
                //printf("%s\n", token);
                strcpy(arr[i/6][i%6],token);
                token = strtok(NULL, delim);
                i++;
            }
            for(int i=0;i<400;i++){
                printf("%s - %s - %s - %s - %s -Avg: " , arr[i][0], arr[i][2], arr[i][3], arr[i][4], arr[i][5]);
                int sum=atoi(arr[i][2])+atoi(arr[i][3])+atoi(arr[i][4])+atoi(arr[i][5]);
                printf("%d\n",sum/4);
            }
        }    //parent process

        if(ret == 0){  //child proces
            char entry[6800];
            char delim[] = ",\n\r";
            read(fd, entry, sizeof(entry));
            char* ptr;
            int chA = 'A';

            ptr = strchr(entry, chA);
            //printf("%s\n", entry);
            //printf("%c \n", (char)entry[33]);
            char *token = strtok(entry, delim);
            char arr[400][6][3];
            int i=0;
            while(token!=NULL){
                //printf("%s\n", token);
                strcpy(arr[i/6][i%6],token);
                token = strtok(NULL, delim);
                i++;
            }
            for(int i=0;i<400;i++){
                int sum=atoi(arr[i][2])+atoi(arr[i][3])+atoi(arr[i][4])+atoi(arr[i][5]);
                int average = sum/4;
                printf("%s - %s - %s - %s - %s -Avg: " , arr[i][0], arr[i][2], arr[i][3], arr[i][4], arr[i][5]);
                //write(STDOUT_FILENO, );
                write(STDOUT_FILENO, &average, sizeof(average));
            }
            sleep(2);
            exit(EXIT_SUCCESS);
        }
    
    }

    else{
        printf("Error!! Unable to open the provided file");
        exit(1);
    }

    close(fd);

    return 0;

}