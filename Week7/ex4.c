#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc (void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    void *result = malloc(size);
    memcpy(result, ptr, size);
    free(ptr);
    return result;
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("Ptr[%d] = %d\n", i, a[i]);
    }
    int m;
    printf("Enter the new size of array: ");
    scanf("%d", &m);
    a = (int*)my_realloc(a, sizeof(int) * m);
    for (int i = n; i < m;++i) {
        a[i] = 0;
    }
    for(int i = 0; i < m; i++){
        printf("Ptr[%d] = %d\n", i, a[i]);
    }
    return 0;
}
