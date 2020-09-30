#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    time_t t;  //define time variable
    time(&t);
    printf("Current date and time: %s", ctime(&t));
    return 0;
}