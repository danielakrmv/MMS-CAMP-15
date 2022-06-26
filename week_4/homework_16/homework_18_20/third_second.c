#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

void* printText(void* arg){
    printf("Pid is: %d\nThread id is:%ld\n", getpid(), pthread_self(), (char*)arg);
}

int main(int argc, char **argv){
    unsigned int P, T;
    P = atoi(argv[1]);
    T = atoi(argv[2]);
    pid_t pid;
    for(int i = 0; i < P; i++){
        pid = fork();
        if(-1 == pid){
            perror("FORK");
            return EXIT_FAILURE;
        }
        if(0 == pid){
            //child
            pthread_t *th = malloc(sizeof(pthread_t)*T);
            for(int j = 0; j < T; j++){
                pthread_create(&th[j], NULL, printText, argv[3]);
            }
            for(int j=0; j <T; j++){
                pthread_join(th[j], NULL);
            }
            exit(EXIT_SUCCESS);
        }
    }
    for(int i= 0; i < P; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}