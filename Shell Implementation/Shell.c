#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for fork
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


void command_prompt(){
    static int first = 1;
    if(first){   //on opening the shell for the first time, clear the screen
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; 
        write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);   //stdout_fileno - file descriptor of system - file no. of stdout = 1, belongs to unistd.h
        first = 0;
    }

    printf("~~#");
}

void read_command(char cmd[], char* para[] ){
    
    char line[1024];
    int count =0, i=0, j=0;
    char* array[100], *pch;

    //reading the input line
    for( ;; ){
        int c = fgetc (stdin);   //gets user input a single character at a time and c stores the number of characters read by it.
        
    }
}



int main(){

    char cmd[100];
    char command_Input[100];
    char* parameter[20];   //to store parameters entered

    char* envp[] = {(char*) "PATH=/bin" , 0};   //defines environment varibles - we assume that all commands are in the directories/bin

    while(1){    //infinite loop 
        command_prompt();   //indicator to enter your command - to present a prompt
        read_command(command_Input, parameter);

        if(fork() != 0){   //parent process

        }
        else{   //child process

        }


        exit(0);
    }


    return 0;
}