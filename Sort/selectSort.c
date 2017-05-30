#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100000
#define MAX_NUM 1000

void selectionSort(int * array, int length);
void printArray(int * array, int length);
void creatRandArray(int * array, int length);

int main(void){
	clock_t start, finish;
	start = clock();

	int randArray[N];
	creatRandArray(randArray, N);

	//printArray(randArray, N);
	selectionSort(randArray, N);
	//printArray(randArray, N);

	finish = clock();
	printf("%f seconds.\n", (double)(finish - start) / CLOCKS_PER_SEC);
	return(0);
}

void selectionSort(int * array, int length){
	int min, minLocation;
	for (int i = 0; i < length; i++) {
		min = *(array + i);
		for (int j = i; j < length; j++) {
			if (*(array + j) < min) {
				min = *(array + j);
				minLocation = j;
			}
		}
		*(array + minLocation) = *(array + i);
		*(array + i) = min;
	}
}

void creatRandArray(int * array, int length){
	for(int n = 0; n < length; n++){
		srand(rand());
		*(array + n) = (int)((double)rand() / RAND_MAX * MAX_NUM);
	}
}

void printArray(int * array, int length){
	for(int n = 0; n < length; n++)
		printf("%d ", *(array + n));
	printf("\n");
}
