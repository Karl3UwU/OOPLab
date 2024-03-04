#include <stdio.h>
#include "NumberList.h";

void NumberList::Init() {
    numbers = new int[size];
    count = 0;
}
void NumberList::Add(int x) {
    if (count >= size) {
        // creating new array
        int newSize = size * 2;
        int *newNumbers = new int[newSize];
        for (int i = 0; i < size; i++)
            newNumbers[i] = numbers[i];
        // deleting old array
        delete []numbers;
        // saving
        size = newSize;
        numbers = newNumbers;
    }
    numbers[count++] = x;
}
void NumberList::Sort() {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[j] < numbers[i]) {
                int aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
        }
    }
}
void NumberList::Print() {
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);
}
