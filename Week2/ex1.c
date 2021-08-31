#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int a = INT_MAX;
	double b = DBL_MAX;
	float c = FLT_MAX;
	printf("INTEGER: size: %lu %d\n", sizeof(a), a);
	printf("DOUBLE: %lu %f\n", sizeof(b), b);
	printf("FLOAT: %lu %f\n", sizeof(c), c);
}
