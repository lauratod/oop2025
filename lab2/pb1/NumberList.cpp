#include "NumberList.h"
#include <stdio.h>
void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	this->numbers[this->count] = x;
	this->count++;
	if (this->count >= 10)return false;
	return true;
}

void NumberList::Sort()
{
	int ok,aux;
	do {
		ok = 0;
		for (int i = 0; i <= this->count - 2; i++)
		{
			if (this->numbers[i] > this->numbers[i + 1])
			{
				ok = 1;
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[i+1];
				this->numbers[i+1] = aux;
			}
		}

	} while (ok == 1);

}

void NumberList::Print()
{
	for (int i = 0; i <= this->count-1; i++)
	{
		printf_s("%d ", this->numbers[i]);
	}
}