#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

Sort::Sort(int nrelemente, int mini, int maxi)
{
	vector = new int[nrelemente];
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i <= nrelemente - 1; i++)
	{
		vector[i] = mini + rand() % (mini - maxi + 1);
	}
	n = nrelemente;
}

Sort::Sort(int* v, int nrelemente)
{
	vector = new int[nrelemente];
	for (int i = 0; i <= nrelemente - 1; i++)
	{
		vector[i] = v[i];
	}
	n = nrelemente;
}

Sort::Sort(int nrelemente, ...) {
	vector = new int[nrelemente];
	n = nrelemente;
	va_list vl;
	va_start(vl, nrelemente);
	for (int i = 0; i <nrelemente; i++)
	{
		vector[i] = va_arg(vl, int);
	}
	va_end(vl);
	
}

Sort::Sort(char* s) {
	int ns = strlen(s);
	int x = 0, cifra,contor=0;
	int nrelemente = 1;
	for (int i = 0; i <= ns - 1; i++)
	{
		if (s[i] == ',')nrelemente++;
	}
	vector = new int[nrelemente];
	for (int i = 0; i <= ns - 1; i++)
	{
		if (s[i] != ',')
		{
			cifra = s[i] - '0';
			x = x * 10 + cifra;
		}
		else
		{
			vector[contor++] = x;
			x = 0;
		}
	}
	vector[contor++] = x;
	x = 0;
	n = nrelemente;
}

Sort::Sort() : vector(new int[6]{ 1, 2, 3, 4, 5, 6 }) {
	n = 6;
}

void Sort::BubbleSort(bool ascendent)
{
	int ok;
	do
	{
		ok = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (ascendent ? vector[i] > vector[i + 1]:vector[i] < vector[i + 1])
			{
				ok = 1;
				int aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
			}
		}
	} while (ok);
}

void Sort::InsertSort(bool ascendent)
{
	int key,j;
	for (int i = 1; i < n; i++)
	{
		key = vector[i];
		j = i - 1;
		while (j >= 0 && (ascendent ? vector[j] > key:vector[j] < key))
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = key;
	}
}

int partition(bool ascendent, int vector[], int st, int dr)//alege un pivot si rearanjeaza elementele
{
	int pivot = vector[dr];
	int i = st - 1;
	for (int j = st; j <= dr - 1; j++)
	{
		if (ascendent? vector[j] < pivot:vector[j] > pivot)
		{
			i++;
			int aux = vector[i]; vector[i] = vector[j]; vector[j] = aux;
		}
	}
	int aux = vector[i+1]; vector[i+1] = vector[dr]; vector[dr] = aux;
	return i + 1;
}

void quick(bool ascendent,int vector[], int st, int dr)//aplica recursiv algoritmul de quicksort
{
	if (st < dr)
	{
		int p = partition(ascendent, vector, st, dr);
		quick(ascendent, vector, st, p - 1);
		quick(ascendent, vector, p + 1, dr);
	}
}

void Sort::QuickSort(bool ascendent)
{
	quick(ascendent, vector, 0, n - 1);
}

int Sort::GetElementsCount()
{
	return n;
}

int Sort::GetElementFromIndex(int index)
{
	return vector[index];
}

void Sort::Print()
{
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}

 