#include <stdio.h>
#include <stdint.h>         
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
        filePath = getenv("SNAP_USER_DATA");
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


