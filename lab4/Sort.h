#pragma once
class Sort
{
    int* vector;
    int n;
public:
    Sort(int nrelemente, int mini, int maxi);
    Sort(int* vector, int nrelemente);
    Sort();
    Sort(int nrelemente, ...);
    Sort(char* s);


    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
