#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char **argv){
    int fd[2]; //масив от два файлови дискриптора

    if(pipe(fd) == -1){
        perror("Error");
        return EXIT_FAILURE;
    } 

    pid_t pid = fork();
    if(0 == pid){
        //child process
        close(fd[0]);
        int sum = 0;
        int middle = (argc - 1) / 2;
        for(int i = middle + 1; i < argc; i++){
            sum += atoi(argv[i]);
            printf("Child num is: %d\n", sum);

        }
        write(fd[1], &sum, sizeof(sum));
        exit(EXIT_SUCCESS);
    }else{
        close(fd[1]);
        int sum = 0;

        for(int i = 1; i < argc/2 + 1; i++){
            sum += atoi(argv[i]);
            printf("Parent num is: %d\n", sum);
        }
        wait(NULL);
        int childNum;
        read(fd[0], &childNum, sizeof(childNum));
        sum += childNum;
        printf("Sum is: %d\n", sum);

    }
    return 0;
}