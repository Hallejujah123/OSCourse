#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int a, b, i, j,z;
  sscanf(argv[1], "%d", &a);
  b = 2 * a - 1;
  for (i = 0; i < a; i++) {
    z=0;
    for (j = 0; j < a; j++) {
      if (j >= (b - (1 + 2 * i)) / 2 && j < b - ((b - (1 + 2 * i)) / 2)) {
        printf("%c", '*');
      }
	  else {
        printf("%c", ' ');
        z++;
      }
    }
    for (j = 0; j < a - z - 1; j++){
      printf("%c", '*');
    }
    for (j = 0; j < z; j++){
      printf("%c", ' ');
    }
    printf("\n");
  }
  return 0;
}
