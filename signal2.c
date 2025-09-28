#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t got_signal = 0;

void handler(int signum)
{
    printf("Hello World!\n");
    got_signal = 1;    
    alarm(5);           
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, handler);  
    alarm(5);                  

    while (1) {
        if (got_signal) {
            printf("Turing was right!\n");
            got_signal = 0;
        }
        usleep(100000); 
    }

    return 0;
}
