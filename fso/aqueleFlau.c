#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void signalScan(int s){
    char cam[11];
    if(scanf(" %s",cam)==EOF)
        exit(0);
    if((s==SIGUSR1&&strcmp(cam, "Igor3k"))||
    (s==SIGUSR2&&strcmp(cam, "Monark"))||
    (s==SIGINT&&strcmp(cam, "Con1"))||
    (s==SIGTERM&&strcmp(cam, "Con2"))||
    (s==SIGALRM&&strcmp(cam, "Silencio")))
        printf("Erro\n");
    else
        printf("Certo\n");

}

int main() {
    signal(SIGINT, signalScan);
    signal(SIGUSR1, signalScan);
    signal(SIGUSR2, signalScan);
    signal(SIGTERM, signalScan);
    signal(SIGALRM, signalScan);

    while(1)
        pause();
}