#include <stdio.h>
#include <unistd.h>

int main(void) {
    int i;
    for (i = 0; i < 3; i++) {
        fork();
    }

    sleep(5);
}
