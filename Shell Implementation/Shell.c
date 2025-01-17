#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for fork
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


void command_prompt();
void read_command(char cmd[], char* para[], char* hI[]);
void cd(char* param[]);
void pwd(char* par[]);
void echo();


char* parameter[20];   //to store parameters entered
char* hist[500];  //to store history of commands entered
int histCounter = 0;

int main(){

    char cmd[200];
    char command[200];
    int ret_ls, ret_rm, ret_mkdir, ret_cat, ret_date;
    int i=0;
    int status;


    while(1){    //infinite loop 

        command_prompt();   //indicator to enter your command - to present a prompt
        read_command(command, parameter, hist);




        //INTERNAL COMMANDS
            if(strcmp(command, "cd") ==0){cd(parameter);}            //cd 
            else if(strcmp(command, "exit") == 0){exit(0);}         //exit 
            else if(strcmp(command, "history") == 0){              //history
                for(int k=0; k<histCounter;k++){
                printf("%s", hist[k]);
                }
            }  
            else if(strcmp(command, "pwd")==0){pwd(parameter);}                     //pwd
            else if(strcmp(command, "echo") ==0){echo(parameter);}        //echo 





        //EXTERNAL COMMANDS
            else if(strcmp(command, "ls") == 0){                         //ls (-a and -F)
                ret_ls = fork();

                if(ret_ls > 0){   //parent process                                
                    waitpid(ret_ls, &status, 0);
                    //printf("\nBack to parent");
                }
                if(ret_ls == 0){  //child process
                    //printf("Welcome to child\n");
                    //command has the name of the file to be executed
                    // parameter has parameters entered by the user with the program

                    char file_name[] = "./";
                    strcat(file_name, command);
                    execv(file_name, parameter);
                    
                    sleep(2);
                }
                if(ret_ls<0){
                    printf("Can't fork\n");
                }
            }



            else if(strcmp(command, "cat") == 0){   //cat
                ret_cat = fork();

                if(ret_cat >0){  //parent process                                
                    waitpid(ret_cat, &status, 0);
                    //printf("\nBack to parent");
                }
                if(ret_cat == 0){  //child process
                    //command has the name of the file to be executed
                    // parameter has parameters entered by the user with the program

                    char file_name[] = "./";
                    strcat(file_name, "cat");
                    
                    execv(file_name, parameter);
                    sleep(2);
                }
                if(ret_cat<0){
                    printf("Can't fork");
                }
            }




            else if(strcmp(command, "date") == 0){    //date
                ret_date = fork();

                if(ret_date >0){  //parent process                                
                    waitpid(ret_date, &status, 0);
                    printf("\nBack to parent");
                }
                if(ret_date == 0){  //child process
                    //command has the name of the file to be executed
                    // parameter has parameters entered by the user with the program

                    char file_name[] = "./";
                    strcat(file_name, "date");
                    execv(file_name, parameter);
                    sleep(2);
                }
                if(ret_date<0){
                    printf("Can't fork");
                }
                
            }





            else if(strcmp(command, "rm") == 0){                 //rm (-i and -d)
                ret_rm = fork();

                if(ret_rm > 0){   //parent process                                
                    waitpid(ret_rm, &status, 0);
                    printf("\nBack to parent");
                }
                if(ret_rm == 0){  //child process
                    //command has the name of the file to be executed
                    // parameter has parameters entered by the user with the program

                    char file_name[] = "./";
                    strcat(file_name, command);
                    
                    execv(file_name, parameter);
                    sleep(2);
                }
                if(ret_rm<0){
                    printf("Can't fork");
                }
                
            }
            

            else if(strcmp(command, "mkdir") == 0){   //mkdir (-v and -m777)
                ret_mkdir = fork();

                if(ret_mkdir > 0){   //parent process                                
                    waitpid(ret_mkdir, &status, 0);
                    printf("\nBack to parent");
                }
                if(ret_mkdir == 0){  //child process
                    //command has the name of the file to be executed
                    // parameter has parameters entered by the user with the program

                    char file_name[] = "./";
                    strcat(file_name, "mkdir");
                    execv(file_name, parameter);
                    sleep(2);
                }
                if(ret_mkdir<0){
                    printf("Can't fork");
                }
            }



            else{    //invalid command entered 
                printf("\nERROR!! COMMAND NOT FOUND\n");
            }

            

            
        for(int p=0; p<20; p++){
            parameter[p] = '\0';
        }
        
    }


    return 0;
}

//prints whatever is entered after the keyword echo
void echo(char* p[]){
   
    for(int q=1; q<20; q++){
        if(p[q]!= NULL){
            printf("%s\n",p[q]);
        }
    }

}


//prints the path of current working directory
void pwd(char* par[]){
    if(par[1] != NULL){
        printf("Can't find %s! Try again", par[1]);
    }
    else{
        char cwd[1024];
        getcwd(cwd,sizeof(cwd));   //gets current working directory path and saves it in cwd
        printf("%s", "\nPATH INFO OF WORKING DIRECTORY: ");
        printf("%s\n", cwd);
    }
}


//changes directory to path provided by user
void cd(char *param[]){
    char path[1000];
    strcpy(path, param[1]);

    //to get current working directory
    char curr[256];
    getcwd(curr, sizeof(curr));

    if(strcmp(param[1], "..")==0){
        int r = chdir("..");  //to go to previous directory
        if(r == 0){
            printf("\nPath Changed Successfully!\n");
        }
        else{
            printf("\nUnsucessful! Path not changed.\n");
        }
    }

    else if(strcmp(param[1], ".") == 0){
        printf("Path - current directory\n");
    }

    else{

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

    }
}


//to indicate that input can be given
void command_prompt(){
    printf("\n~~#");
}



// to take, read and breakdown the user input 
void read_command(char cmd[], char* para[], char* hI[]){
    
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

    hI[histCounter] = strdup(line);
    hI[histCounter+1] = NULL;
    histCounter++;

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
    //printf("%s\n", cmd);

    //rest tokens will be parameters
    for(int j=0; j<i; j++){
        para[j] = array[j];
        //printf("%s\n",para[j]);
    }
    para[i] = NULL;    //make the end of parameter array NULL
    memset(line, '\0', 1024);   //changes all the characters in the line array to null
}
