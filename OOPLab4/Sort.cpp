#include "Sort.h"
#include "random"
#include "ctime"
#include <cstring>
#include <stdarg.h>
#include <iostream>

int castToInt(char* s) {
	int x = 0;
	for (int i = 0; s[i]; i++)
		x = x * 10 + (s[i] - '0');
	return x;
}

Sort::Sort(int size, int min, int max) {
	srand(time(NULL));
	int diff = max - min;
	
	max_size = size;
	length = size;
	arr = new int[size];
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % diff + min;
	}
}

Sort::Sort(std::initializer_list<int> il) {
	max_size = il.size();
	length = il.size();

	arr = new int[max_size];
	std::copy(il.begin(), il.end(), arr);
}

Sort::Sort(int *source, int size) {
	max_size = size;
	length = size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = source[i];
}

Sort::Sort(char *source) {
	// counting how many elemets
	int size = 1;
	for (int i = 0; source[i]; i++)
		if (source[i] == ',') size++;
	
	arr = new int[size];
	max_size = size;
	length = 0;
	for (char* t = strtok(source, ","); t; t = strtok(NULL, ",")) {
		arr[length++] = castToInt(t);
	}
}

Sort::Sort(int count, ...) {
	max_size = count;
	length = count;

	arr = new int[count];
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i) {
		arr[i] = va_arg(args, int);
	}
	va_end(args);
}

//// ------------------------------------------------------------

int Sort::GetElementsCount() {
	return length;
}

int Sort::GetElementFromIndex(int index) {
	return arr[index];
}

void Sort::Print() {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

static bool checkSwap(int a, int b, bool asc) {
	if (asc) return a > b;
	return a < b;
}

void Sort::InsertSort(bool ascendant) {
	for (int i = 1; i < length; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && checkSwap(arr[i], arr[j], ascendant)) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int Sort::Partition(int low, int high, bool ascendent) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (ascendent ? arr[j] < pivot : arr[j] > pivot) {
			i++;
			int aux = arr[i];
			arr[i] = arr[j];
			arr[j] = aux;
		}
	}
	int aux = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = aux;
	return (i + 1);
}

void Sort::QuickSortImpl(int low, int high, bool ascendant) {
	if (low < high) {
		int pi = Partition(low, high, ascendant);

		QuickSortImpl(low, pi - 1, ascendant);
		QuickSortImpl(pi + 1, high, ascendant);
	}
}

void Sort::QuickSort(bool ascendant) {
	QuickSortImpl(0, length - 1, ascendant);
}