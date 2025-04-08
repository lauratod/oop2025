#include "Student.h"
#include "Compara.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int comparaNume(const Student& s1, const Student& s2)
{
	return strcmp(s1.GetName(), s2.GetName());
}

int comparaNotaMate(Student& s1, Student& s2)
{
	if (s1.GetNotaMate() > s2.GetNotaMate())return 1;
	else if (s1.GetNotaMate() < s2.GetNotaMate())return -1;
	return 0;
}


int comparaNotaEngleza(Student& s1, Student& s2)
{
	if (s1.GetNotaEngleza() > s2.GetNotaEngleza())return 1;
	else if (s1.GetNotaEngleza() < s2.GetNotaEngleza())return -1;
	return 0;
}


int comparaNotaIstorie(Student& s1, Student& s2)
{
	if (s1.GetNotaIstorie() > s2.GetNotaIstorie())return 1;
	else if (s1.GetNotaIstorie() < s2.GetNotaIstorie())return -1;
	return 0;
}


int comparaMedie(Student& s1, Student& s2)
{
	if (s1.media() > s2.media())return 1;
	else if (s1.media() < s2.media())return -1;
	return 0;
}