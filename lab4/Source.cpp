#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	Sort v1(7, 1, 100);
	v1.Print();
	printf("elementul cu indexul 2 este %d \n", v1.GetElementFromIndex(2));
	Sort v2;
	v2.Print();
	char s[] = "12,100,56,2,1,90,83,4";
	Sort v3(s);
	v3.Print();
	printf("numarul de elemente este %d \n", v3.GetElementsCount());
	v3.QuickSort(0);//0-descrescator si 1-crescator
	v3.Print();
	Sort v4(4, 23, 12, 1, 42);
	v4.BubbleSort(1);
	v4.Print();
	int vect[] = { 12,4,5 };
	Sort v5(vect, 3);
	v5.Print();
	v5.InsertSort(1);
	v5.Print();
	return 0;
}