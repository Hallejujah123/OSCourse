#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char command[1000];
    while(1) {
        scanf("%s", command);
        system(command);
    }
}
