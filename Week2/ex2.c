#include <stdio.h>
#include <string.h>

int main(void) {
	printf("ENTER STRING: ");
	char str[100000], i, new_str[100000];
	fgets(str, 10, stdin);
	for (i = 0; i < strlen(str); i++) {
		new_str[i] = str[strlen(str) - i - 1]; 
		}
	printf("%s", new_str);
	return 0;
}
