#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
    time_t t;  //define time variable
    time(&t);

    struct tm *uniTime;

    if(strcmp(argv[1], "-u")==0){
        uniTime = gmtime(&t);
        printf("Current UTC Time (hr:min:sec) - 24 hour clock: %d:%d:%d" , uniTime->tm_hour, uniTime->tm_min, uniTime->tm_sec);
    }
    else{
        printf("Current date and time: %s\n", ctime(&t));
    }
    
    return 0;
}