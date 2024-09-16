#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <timefunctions.h>

#undef FILE_PRINT

int main(){
    uint64_t count = 0;
    char *filePath;

    #ifdef _WIN32
        filePath = "log.csv";
    #endif
    #ifdef __linux__
        char *fileRoot = getenv("SNAP_USER_DATA");
        if (val == NULL)
        {
            printf("Cannot find enviroment variable");
        }
        else:
            printf("%s\n", fileRoot);
            strcat(filePath, fileRoot);
            printf("%s\n", filePath);
            strcat(filePath. "/log.csv");
            printf("%s\n", filePath);
    #endif

    #ifdef FILE_PRINT
        record = fopen(filePath, "a");
        while (count < 10){
            count += 1;
            fprintf(record, "Entering Log, %d\n", count);
            scriptSleep(1000);
            #ifdef _WIN32
                printf("Update Entry\n");
            #endif
        }
    #endif
    return 0;
}


