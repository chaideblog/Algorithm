#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
#define MAX_NUM 1000

void creatRandArray(int * array, int length);
void printArray(int * array, int length);
void insertSort(int * array, int length);

int main(void){
	clock_t start, finish;
	start = clock();

	int randArray[N];
	creatRandArray(randArray, N);

	//printArray(randArray, N);
	insertSort(randArray, N);
	//printArray(randArray, N);

	finish = clock();
	printf("%f seconds.\n", (double)(finish - start) / CLOCKS_PER_SEC);
	return 0;
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
		*(array + n) = (int)((double)rand() / RAND_MAX * MAX_NUM);
	}
}
