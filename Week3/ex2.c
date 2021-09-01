#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int arr[], int n){
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

int main(void) {
	int n, i;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	bubbleSort(arr, n);
	printf("Sorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
