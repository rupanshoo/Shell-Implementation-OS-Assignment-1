#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
    time_t t;  //define time variable
    time(&t);

    struct tm *uniTime;
    struct tm tim;

    if(argv[1][0] >=0 && argv[1][0]<=127 ){

    if(strcmp(argv[1], "-u")==0){
        uniTime = gmtime(&t);
        printf("Current UTC Time (hr:min:sec) - 24 hour clock: %d:%d:%d" , uniTime->tm_hour, uniTime->tm_min, uniTime->tm_sec);
    }

    else if(strcmp(argv[1], "-s")==0){
        printf("Can't set date as not permitted by System\n");
        printf("Date Entered in format [dd mm yyyy] : %s/%s/%s\n", argv[2], argv[3], argv[4]);
    }

    else{
        printf("error!\n");
        return 0;
    }

   }

    else{
        printf("Current date and time: %s\n", ctime(&t));
    }
    
    return 0;
}