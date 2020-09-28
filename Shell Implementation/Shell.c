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
void history();


int main(){

    char cmd[100];
    char command[100];
    char* parameter[20];   //to store parameters entered
    //int stat;

    //int ret = fork();

    //char* envp[] = {(char*) "PATH=/bin" , 0};   //defines environment varibles - we assume that all commands are in the directories/bin

    while(1){    //infinite loop 
        command_prompt();   //indicator to enter your command - to present a prompt
        read_command(command, parameter);
        
        //INTERNAL COMMANDS
            if(strcmp(command, "cd") ==0){cd();}                //cd 
            if(strcmp(command, "exit") == 0){exit(0);}         //exit 
            if(strcmp(command, "history") == 0){history();}   //history
        
    }


    return 0;
}

void history(){

}


void cd(){
    printf("cd executed\n");
}


void command_prompt(){
    /*static int first = 1;
    if(first){   //on opening the shell for the first time, clear the screen
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; 
        write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);   //stdout_fileno - file descriptor of system - file no. of stdout = 1, belongs to unistd.h
        first = 0;
    }
*/
    printf("#");
}




void read_command(char cmd[], char* para[]){
    
    char line[1024];
    int count =0, i=0, j=0;
    char* array[100], *pch;

    //reading the input line
    for( ;; ){
        int c = fgetc (stdin);   //gets user input a single character at a time and c stores the number of characters read by it.
        line[count++] = (char) c;
        if(c == '\n')    //to check end of the command being entered.
        {break;}
    }

    if(count == 1){   //in case of only one character entered
        return;
    }

    //for more than one enters
    pch = strtok(line, " \n");

    while( pch!= NULL){
        array[i++] = strdup(pch);   //to save a duplicate of the token in array
        pch = strtok(NULL, " \n");
    }

    //the first word entered is the command
    strcpy(cmd, array[0]);

    //rest tokens will be parameters
    for(int j=0; j<i; j++){
        para[j] = array[j];
        para[i] = NULL;    //make the end of parameter array NULL
    }

}