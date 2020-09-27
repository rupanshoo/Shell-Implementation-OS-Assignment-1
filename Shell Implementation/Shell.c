#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for fork
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


void command_prompt();
void read_command(char cmd[], char* para[]);
void cd();


int main(){

    char cmd[100];
    char command_Input[100];
    char* parameter[20];   //to store parameters entered
    int stat;

    int ret = fork();

    char* envp[] = {(char*) "PATH=/bin" , 0};   //defines environment varibles - we assume that all commands are in the directories/bin

    while(1){    //infinite loop 
        command_prompt();   //indicator to enter your command - to present a prompt
        read_command(command_Input, parameter);

        if(ret > 0){   //parent process
            waitpid(ret, &stat, 0);
            if (WIFSIGNALED(stat)){
                printf("Error\n");
            }
            else if (WEXITSTATUS(stat)) {
                printf("Exited Normally\n");
            }

        }


        if(ret == 0){   //child process
            strcpy(cmd, "/bin/");
            strcat(cmd, command_Input);
            execve(cmd, parameter, envp);   //to execute the command

            sleep(2);
        }

        if(strcmp(command_Input, "exit") == 0){break;}   //exit internal command
        if(strcmp(command_Input, "cd") ==0){
            cd();
        }
    }


    return 0;
}


void cd(){
    
}


void command_prompt(){
    static int first = 1;
    if(first){   //on opening the shell for the first time, clear the screen
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; 
        write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);   //stdout_fileno - file descriptor of system - file no. of stdout = 1, belongs to unistd.h
        first = 0;
    }

    printf("#");
}




void read_command(char cmd[], char* para[]){
    
    char line[1024];
    int count =0, i=0, j=0;
    char* array[100], *pch;
    char delim[] ="\n"; 

    //reading the input line
    for( ;; ){
        int c = fgetc (stdin);   //gets user input a single character at a time and c stores the number of characters read by it.
        line[count++] = (char) c;
        if(c == '\n')    //to check end of the command being entered.
        {break;}
    }

    if(count == 1){   //in case of only one enter
        return;
    }

    //for more than one enters
    pch = strtok(line, delim);

    while( pch!= NULL){
        array[i++] = strdup(pch);   //to save a duplicate of the token in array
        pch = strtok(NULL, delim);
    }

    //the first word entered is the command
    strcpy(cmd, array[0]);

    //rest tokens will be parameters
    for(int j=0; j<i; j++){
        para[j] = array[j];
        para[i] = NULL;    //make the end of parameter array NULL
    }

}