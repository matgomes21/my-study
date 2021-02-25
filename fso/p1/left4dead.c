#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int c=0;
pid_t x;
void signalScan(int s){
    if(c==0){
        x = fork();
        if(x==0)
            exit(0);
    }
    else if(c==1){
        wait(NULL);
    }
    else{
        exit(0);
    }
    c++;
}

int main() {
    signal(SIGUSR1, signalScan);
    signal(SIGUSR2, signalScan);

    while(1)
        pause();
}