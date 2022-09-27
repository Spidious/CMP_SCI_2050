#include "lab3.h"

void printArray(int *array, int size) {
	printf("[ ");
	for(int i = 0; i < size; ++i) {
		printf("%d", array[i]);
		if((i + 1) == size) {
			printf(" ]\n");
		} else {
			printf(", ");
		}
	}
}

int main() {
	srand(time(NULL));

	int size = 20, offset = 30;

	int *array = makeArray(size);
	printArray(array, size);

	array = offsetArray(array, offset);

	printFives(array, size, offset);

	freeArray(array, offset);
}

