#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int pwd=0;

void signalScan(int signal){
    printf("Recebi %d\n",signal);
    if(signal==SIGINT)
        pwd=1;
    else if(pwd==1 && signal==SIGUSR2)
        pwd=2;
    else if(pwd==2 && signal==SIGTERM){
        pwd=3;
        printf("Senha acionada\n");
    }
    else if(pwd==3 && signal==SIGUSR1){
        printf("Tchau\n");
        exit(0);
    }
    else
        pwd=0;
}

int main() {
    signal(SIGINT, signalScan);
    signal(SIGUSR1, signalScan);
    signal(SIGUSR2, signalScan);
    signal(SIGTERM, signalScan);

    while(1)
        pause();
}