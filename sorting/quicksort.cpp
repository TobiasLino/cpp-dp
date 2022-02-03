// C. A. R. Hoare
// Quicksort

#include <iostream>

void swap(int* a, int* b) {
	int x = *a;
	*a = *b;
	*b = x;
}

//template<class T>
void quicksort(int* data, int start, int end) {
	int lower = start + 1, upper = end;
	swap(&data[start], &data[(start + end) / 2]);

	int bound = data[start];
	while (lower <= upper) {
		while (data[lower] < bound)
			++lower;
		while (bound < data[upper])
			--upper;
		if (lower < upper)
			swap(&data[++lower], &data[--upper]);
		else
			++lower;
	}

	swap(&data[upper], &data[start]);

	if (start < upper - 1)
		quicksort(data, start, upper - 1);
	if (upper + 1 < end)
		quicksort(data, upper + 1, end);
}

void quicksort(int data[], int n) {
	if (n < 2) 
		return;
	for (int i = 1, max = 0; i < n; ++i) {
		if (data[max] < data[i])
			max = i;
		swap(&data[n - 1], &data[max]);
	}
	quicksort(data, 0, n - 2);
}

void imprime(int data[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << data[i] << ", ";
	}
	std::cout << std::endl;
}

int* randomize(int size, int range) {
	int* l = new int[size];
	for (int i = 0; i < size; ++i) {
		l[i] = rand() % range;
	}

	return l;
}

int main() {
	int size = 10;
	int data[10] = {5,2,7,6,1,9,3,8,10,4};
	int* d = randomize(100, 100);
	imprime(d, size);
	quicksort(d, size);
	imprime(d, size);

	delete[] d;

	return EXIT_SUCCESS;
}
