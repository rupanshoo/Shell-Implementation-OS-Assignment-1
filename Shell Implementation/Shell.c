#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for fork
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


void command_prompt();
void read_command(char cmd[], char* para[]);
void cd(char* param[]);
void history();
void pwd();


char* parameter[20];   //to store parameters entered

int main(){

    char cmd[200];
    char command[200];
    int i=0;

    while(1){    //infinite loop 

        for(int y=0; y<20; y++){
            if(parameter[y]!=NULL){
                parameter[y] = NULL;
            }
            printf("%s", parameter[y]);
        }
        command_prompt();   //indicator to enter your command - to present a prompt
        read_command(command, parameter);


        //to check values in parameter
        for(int k=0; k<20;k++){
            printf("%s", parameter[k]);
        }

        
        //INTERNAL COMMANDS
            if(strcmp(command, "cd") ==0){cd(parameter);}       //cd 
            if(strcmp(command, "exit") == 0){exit(0);}         //exit 
            if(strcmp(command, "history") == 0){history();}   //history
            if(strcmp(command, "pwd")==0) {pwd();}           //pwd
        
    }


    return 0;
}

void pwd(){

}

void history(){

}


void cd(char *param[]){
    char path[1000];
    strcpy(path, param[1]);

    //to get current working directory
    char curr[256];
    getcwd(curr, sizeof(curr));


    //to build the correct format for new path
    strcat(curr, "/");   
    strcat(curr, path);
    printf("%s", curr);

    int ret = chdir(curr);  //change current directory to new path provided
    if(ret == 0){
        printf("\nPath Changed Successfully!\n");
    }
    else{
        printf("\nUnsucessful! Path not changed.\n");
    }

    /*
    //to remove all previous parameters
    for(int x=0; x<20; x++){
        if(param[x] != NULL){
            param[x] = NULL;
        }
        //printf("%s",param[x]);
    }
    */
}



void command_prompt(){
    /*
    static int first = 1;
    if(first){   //on opening the shell for the first time, clear the screen
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; 
        write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);   //stdout_fileno - file descriptor of system - file no. of stdout = 1, belongs to unistd.h
        first = 0;
    }
    */
    printf("\n~~#");
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

    /*
    for(int k=0; sizeof(k); k++){
        printf("%c", line[k]);
    }
    */

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
    printf("%s\n", cmd);

    //rest tokens will be parameters
    for(int j=0; j<i; j++){
        para[j] = array[j];
        printf("%s\n",para[j]);
        para[i] = '\0';    //make the end of parameter array NULL
    }
}
