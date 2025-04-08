#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int math::Add(int a, int b, int c)
{
	return a + b + c;
}

int math::Add(int a, int b)
{
	return a + b;
}

int math::Add(double a, double b)
{
	return a + b;
}

int math::Add(double a, double b, double c)
{
	return a + b + c;
}

int math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int math::Mul(int a, int b)
{
	return a * b;
}

int math::Mul(double a, double b)
{
	return a * b;
}

int math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int math::Add(int count, ...)
{
	va_list nr;//declara un obiect nr de tip va_list
	va_start(nr, count);//initializeaza lista de argumente variabile, specificand ca incep dupa count
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += va_arg(nr, int);//extrage cate un argument
	}
	va_end(nr);//curata resursele folosite de va_list
	return total;
}

/*
char* math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)return nullptr;
	int n = strlen(a) + strlen(b)+1;
	char* c;

}
*/

char* math::Add(const char* str1, const char* str2) {
	if (!str1 || !str2) {
		return nullptr;
	}

	int n1 = strlen(str1);
	int n2 = strlen(str2);
	int n = n1 + n2 + 1; 

	char* result = new char[n];
	if (!result) {
		return nullptr;
	}

	strcpy_s(result, n, str1);   //dest, dest_size, src
	strcat_s(result, n, str2);

	return result;
}
