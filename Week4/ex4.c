#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char command[1000];
    char *argv[1000];
    while(1) {
        fgets(command, 1000, stdin);
        for (int i = 0; i < 1000; i++) {
            if (command[i] == '\n') {
                command[i] = '\0';
            }
        }
        int index = 0;
        argv[index] = strtok(command, " ");
        while (argv[index] != NULL) {
            index++;
            argv[index] = strtok(NULL, " ");
        }
        int pid = getpid();
        fork();
        if (getpid() != pid) {
            execvp(argv[0], argv);
        }
    }
}
