#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int c=0;

void signalScan(int signal){
    if(signal==SIGUSR1)
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    else if(signal==SIGALRM && c<2){
        printf("Ai que sono, quero dormir mais um pouco\n");
        c++;
    }
    else{
        printf("Os incomodados que se mudem, tchau\n");
        exit(0);
    }
}

int main() {
    signal(SIGUSR1, signalScan);
    signal(SIGALRM, signalScan);

    while(1)
        pause();
}