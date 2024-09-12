#include <timefunctions.h>
#ifdef _WIN32
    #include <Windows.h>
#endif
#ifdef __linux__
    #include <unistd.h>
#endif

void scriptSleep(int msTime){
    #ifdef _WIN32
        Sleep(msTime);
    #endif

    #ifdef __linux__
        sleep(msTime / 1000);
    #endif
}
