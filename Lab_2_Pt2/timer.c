#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t got_signal = 0;
volatile sig_atomic_t seconds_passed = 0;

void alarm_handler(int signum)
{
    printf("Hello World!\n");
    got_signal = 1;    
    seconds_passed++;
    alarm(1);          
}

void int_handler(int signum)
{
    printf("\nTotal time running: %d seconds\n", seconds_passed);
    exit(0);
}

int main()
{
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, int_handler);

    alarm(1);  

    while (1) {
        if (got_signal) {
            printf("Turing was right!\n");
            got_signal = 0;
        }
        usleep(100000);  
    }

    return 0;
}
