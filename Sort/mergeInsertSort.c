#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100000
#define MAX_NUM 1000

void creatRandArray(int * array, int length);
void printArray(int * array, int length);
void sort(int * array, int start, int finish);
void mergeSort(int * array, int start, int mid, int finish);
void insertSort(int * array, int length);

int main(void){
	clock_t start, finish;
	start = clock();

	int randArray[N];
	creatRandArray(randArray, N);
	//printArray(randArray, N);
	sort(randArray, 0, N - 1);
	//printArray(randArray, N);

	finish = clock();
	printf("%f seconds.\n", (double)(finish - start) / CLOCKS_PER_SEC);
	return(0);
}

void printArray(int * array, int length){
	for(int n = 0; n < length; n++)
		printf("%d ", *(array + n));
	printf("\n");
}

void sort(int * array, int start, int finish) {
	if (finish <= start) return;
	int mid = start + (finish - start) / 2;
	if (finish - start < 7)
		insertSort(array + start, finish - start + 1);
	else {
		sort(array, start, mid);
		sort(array, mid + 1, finish);
		mergeSort(array, start, mid, finish);
	}
}

void insertSort(int * array, int length){
	int temp = 0;
	for(int i = 1; i < length; i++) {
		for (int j = i; (j > 0) & (*(array + j - 1) > *(array + j)); j--) {
			int temp = *(array + j);
			*(array + j) = *(array + j - 1);
			*(array + j - 1) = temp;
		}
	}
}

void mergeSort(int * array, int start, int mid, int finish){
	int i = start;
	int j = mid + 1;
	int temp[finish + 1];

	for (int k = start; k <= finish; k++)
		temp[k] = *(array + k);

	for (int k = start; k <= finish; k++) {
		if	(i > mid)		*(array + k) = temp[j++];
		else if	(j > finish)		*(array + k) = temp[i++];
		else if (temp[i] > temp[j])	*(array + k) = temp[j++];
		else				*(array + k) = temp[i++];
	}
}

void creatRandArray(int * array, int length){
	for(int n = 0; n < length; n++){
		srand(rand());
		*(array + n) = (int)((double)rand() / RAND_MAX * MAX_NUM);
	}
}

