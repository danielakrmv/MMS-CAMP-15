#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

char* randomName(char *name);
int randint(int min, int max);

int main(int argc, char** argv){
    int N = atoi(argv[1]);

    for(int i = 1; i<= N; i++){
        srand(time(NULL) + i);
        pid_t pid = fork();
        if(-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if(0 == pid){
            char buffer[11];
            printf("%s\n", randomName(buffer));
            exit(EXIT_SUCCESS);
        }
    }
    for(int i = 0; i < N; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;

}


char* randomName(char *name)
{
    unsigned index = 0;
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        name[index++] = randint('a', 'z');
    }

    name[index] = '\0';
    return name;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}