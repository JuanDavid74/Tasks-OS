#include "maxrand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char **argv) {
    pid_t pid;
    int res;

    pid = fork();
    if (pid == 0) {
        printf("child\n");
        exit(1);
    }

    pid = wait(&res);
    printf("raw res=%d\n", res);

    if (WIFEXITED(res))
        printf("exit status = %d\n", WEXITSTATUS(res));
    return 0;
}
