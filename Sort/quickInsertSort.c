#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100000
#define MAX_NUM 1000
#define M 7

void creatRandArray(int * array, int length);
void printArray(int * array, int length);
void quickSort(int * array, int start, int finish);
int partition(int * array, int start, int finish);
void insertSort(int * array, int length);

int main(void){
	clock_t start, finish;
	start = clock();

	int randArray[N];
	creatRandArray(randArray, N);
	//printArray(randArray, N);
	quickSort(randArray, 0, N - 1);
	//printArray(randArray, N);

	finish = clock();
	printf("%f seconds.\n", (double)(finish - start) / CLOCKS_PER_SEC);
	return(0);
}

void quickSort(int * array, int start, int finish) {
	if (finish <= start + M) {
		insertSort(array + start, finish - start + 1);
		return;
	}
	int j = partition(array, start, finish);
	quickSort(array, start, j - 1);
	quickSort(array, j, finish);
}

int partition(int * array, int start, int finish) {
	int i = start + 1, j = finish;
	int v = *(array + start);
	while (1) {
		for (; (i < j) & *(array + i) <= v; i++);
		for (; (i < j) & *(array + j) >= v; j--);
		if (i >= j) break;
		int temp = *(array + j);
		*(array + j) = *(array + i);
		*(array + i) = temp;
	}
	*(array + start) = *(array + j - 1);
	*(array + j - 1) = v;
	return j;
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

void printArray(int * array, int length){
	for(int n = 0; n < length; n++)
		printf("%d ", *(array + n));
	printf("\n");
}

void creatRandArray(int * array, int length){
	for(int n = 0; n < length; n++){
		srand(rand());
		*(array + n) = (int)((double)rand() / RAND_MAX * MAX_NUM);
	}
}


