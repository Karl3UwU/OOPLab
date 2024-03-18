#pragma once
#include <initializer_list>

class Sort
{
private:
    int *arr;
    int max_size, length;
public:
    Sort(int size, int min, int max);
    Sort(std::initializer_list<int> il);
    Sort(int *source, int size);
    Sort(int count, ...);
    Sort(char *source);

    int Partition(int low, int high, bool ascendent);

    void InsertSort(bool ascendent = false);
    void QuickSortImpl(int low, int high, bool ascendant);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};