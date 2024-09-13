#include <stdio.h>
#include <stdint.h>
#include <string.h>         
#include <stdlib.h>         /*To get enviroment variables on ubuntu*/
#include <timefunctions.h>  /*Package created to get universal sleep function on windows and linux*/

int main(){
    uint64_t count = 0;
    FILE *record;
    char *filePath;

    #ifdef _WIN32
        filePath = "log.csv";
    #endif
    #ifdef __linux__
        char *fileRoot = getenv("SNAP_USER_DATA");
        printf("%s", fileRoot);
        strcat(filePath, fileRoot);
        printf("%s", filePath);
        strcat(filePath, "/log.csv");
        printf("%s", filePath);
    #endif

    record = fopen(filePath, "a");
    while (count < 10){
        count += 1;
        fprintf(record, "Entering Log, %d\n", count);
        scriptSleep(1000);
        #ifdef _WIN32
            printf("Update Entry\n");
        #endif
    }
    return 0;
}


