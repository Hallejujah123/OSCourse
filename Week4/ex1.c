#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid;
    pid = fork();
    if (pid == 0) {
        printf("Hello from child [PID - %d]\n", getpid());
    } else {
        printf("Hello from parent [PID - %d]\n", getpid());
    }
}
