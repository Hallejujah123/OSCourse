#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid;
    pid = fork();
    if (pid == 0) {
        printf("HELLO FROM PARENT [PID - %d]\n", getpid());
    } else {
        printf("HELLO FROM CHILD [PID - %d]\n", getpid());
    }
}
