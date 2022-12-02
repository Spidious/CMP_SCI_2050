#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	float height;
	double kilometers;
} Runner;

// O(n^2)
void sortByAge(Runner *array, int size);

// O(log(n))
int getByAge(Runner *array, int size, int age);
