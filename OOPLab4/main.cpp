#include <iostream>
#include "Sort.h"

int main() {
    // Using constructor with random values within a specific interval
    Sort randomSort(10, 1, 100);
    randomSort.Print();

    // Using constructor with an initializer list
    Sort initListSort({ 5, 2, 9, 1, 5, 6 });
    initListSort.Print();

    // Using constructor with an existing vector
    int vector[] = {4, 5, 6, 3, 2, 1};
    Sort vectorSort(vector, 6);
    vectorSort.Print();

    // Using variadic parameters constructor
    Sort variadicSort(5, 10, 40, 100, 5, 70);
    variadicSort.Print();

    // Using constructor with a string
    char s[] = "10,40,100,5,70";
    Sort stringSort(s);
    stringSort.Print();

    stringSort.QuickSort(false);
    stringSort.Print();

    return 0;
}
