#include <stdio.h>
#include <stdint.h>
#include <timefunctions.h>

int main(){
    uint64_t count = 0;
    FILE *record;
    char *filePath;

    #ifdef _WIN32
        filePath = "log.csv";
    #endif
    #ifdef __linux__
        filePath = "/home/ubuntu/snap/csvcounter/common/log.csv";
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


