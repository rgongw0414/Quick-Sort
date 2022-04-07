#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int partition(int* arr, int left, int right, int pivot);
void quicksort(int* arr, int left, int right);

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(int argc, char* argv[]){
	int len = atoi(argv[1]);
	if (len <= 0) return 1;

	int* arr = malloc(sizeof(int)*len);
	srand(time(0));
	for (int i = 0; i < len; i++){
		arr[i] = rand() % 100;
		printf("%2d ", arr[i]);
	}
	putchar('\n');
	
	quicksort(arr, 0, len-1);
	for (int i = 0; i < len; i++){
		printf("%2d ", arr[i]);
	}
	putchar('\n');
}



int partition(int* arr, int left, int right, int pivot){
	int pivotValue = arr[pivot];
	swap(&arr[pivot], &arr[right]);
	int storeIndex = left;
	for (int i = left; i < right; i++){
		if (arr[i] < pivotValue){
			swap(&arr[storeIndex], &arr[i]);
			storeIndex++;
		}
	}
	swap(&arr[right], &arr[storeIndex]);
	return storeIndex;
}


void quicksort(int* arr, int left, int right){
	if (right > left){
		int pivotValue = arr[left];
		int pivotNewIndex = partition(arr, left, right, left);
		quicksort(arr, left, pivotNewIndex-1);
		quicksort(arr, pivotNewIndex+1, right);
	}
}

