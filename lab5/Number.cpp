#include "Number.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int Number::chartoint(char c)const
{
	if (c >= '0' && c <= '9')return (c - '0');
	else return (c - 'A' + 10);
}


char Number::inttochar(int c)const
{
	if (c <= 9)return (c + '0');
	else return (c - 10 + 'A');
}


int Number::tobaza10()const
{
	int x = 0;
	for (int i = 0; i <= this->length - 1; i++)
	{
		x = x * base + chartoint(nr[i]);
	}
	return x;
}


void Number::frombaza10(int x, int b)
{
	char* s;
	s = new char[51];
	int n = 0;
	do
	{
		s[n++] = inttochar(x % b);
		x /= b;
	} while (x != 0);
	s[n] = '\0';
	base = b;
	length = n;

	
	char* aux;
	aux = new char[n + 1];
	n--;
	for (int i = 0; i <= length - 1; i++)
	{
		aux[i] = s[n--];
	}
	aux[length] = NULL;
	

	delete[] nr;  // Eliberăm memoria veche
	nr = new char[length + 1];  // Alocăm buffer suficient
	strcpy_s(nr, length + 1, aux);

}

void Number::SwitchBase(int b) {
	int val = tobaza10();
	frombaza10(val, b);
}

Number::Number()
{
	length = 1;
	this->nr = new char[length + 1];
	nr[0] = '0';
	nr[1] = NULL;
	base = 10;
}

Number::Number(const char* value, int base)
{

	length = strlen(value);
	this->nr = new char[length + 1];
	strcpy_s(nr, length + 1, value);
	this->base = base;

}

Number::Number(const Number& n)//copy constructor
{
	base = n.base;
	length = n.length;
	nr = new char[length + 1];
	strcpy_s(nr, length + 1, n.nr);
}

Number::Number(Number&& n)//move constructor
{
	base = n.base;
	length = n.length;
	nr = n.nr;
	n.base = 0;
	n.length = 0;
	n.nr = nullptr;
	printf("move constructor called! \n");
}

Number::Number(int x)
{
	frombaza10(x, 10);
}

Number::~Number()
{
	delete[] nr;
}

Number& Number::operator=(const Number& n)
{
	delete[] nr;
	base = n.base;
	length = n.length;
	nr = new char[length + 1];
	strcpy_s(nr, length + 1, n.nr);
	return *this;
}

Number& Number::operator=(const char* val)
{
	delete[] nr;
	length = strlen(val);
	nr = new char[length + 1];
	strcpy_s(nr, length + 1, val);
	return *this;
}

Number& Number::operator=(int val)
{
	int b = base;
	frombaza10(val, 10);
	SwitchBase(2);
	return *this;
}


void Number::Print()
{
	printf("%s (base %d)\n", this->nr, this->base);
}

bool Number::operator==(const Number& n)const
{
	if (tobaza10() == n.tobaza10())return true;
	return false;
}

bool Number::operator!=(const Number& n)const
{
	if (tobaza10() == n.tobaza10())return false;
	return true;
}

bool Number::operator<(const Number& n)const
{
	if (tobaza10() < n.tobaza10())return true;
	return false;
}

bool Number::operator<=(const Number& n)const
{
	if (tobaza10() <= n.tobaza10())return true;
	return false;
}

bool Number::operator>(const Number& n)const
{
	if (tobaza10() > n.tobaza10())return true;
	return false;
}

bool Number::operator>=(const Number& n)const
{
	if (tobaza10() >= n.tobaza10())return true;
	return false;
}

char Number::operator[](int index)
{
	if (index < 0 || index >= length)throw "Index out of range";
	return nr[index];
}

Number operator+(const Number& n1, const Number& n2)
{
	Number sum;
	if (n1.base > n2.base)sum.base = n1.base;
	else sum.base = n2.base;
	int s = n1.tobaza10() + n2.tobaza10();
	sum.frombaza10(s, sum.base);
	return sum;
}

Number operator-(const Number& n1, const Number& n2)
{
	Number dif;
	if (n1.base > n2.base)dif.base = n1.base;
	else dif.base = n2.base;
	int d = n1.tobaza10() - n2.tobaza10();
	dif.frombaza10(d, dif.base);
	return dif;
}

Number& Number::operator--()
{
	for (int i = 1; i <= length; i++)
	{
		nr[i - 1] = nr[i];
	}
	length = length - 1;
	if (length == 0)
	{
		length = 1;
		nr[0] = '0';
		nr[1] = NULL;
	}
	return *this;
}

Number Number::operator--(int)
{
	nr[length - 1] = NULL;
	length = length - 1;
	if (length == 0)
	{
		length = 1;
		nr[0] = '0';
		nr[1] = NULL;
	}
	return *this;
}

Number& Number::operator+=(const Number& n)
{
	*this = *this + n;
	return *this;
}

int Number::GetDigitsCount()
{
	return length;
}

int Number::GetBase()
{
	return base;
}

