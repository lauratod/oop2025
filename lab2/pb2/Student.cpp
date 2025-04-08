#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

const char* Student::GetName() const
{
	return nume;
}

void Student::SetName(const char* s)
{
	int n = strlen(s);
	this->nume = new char[n + 1];
	strcpy_s(nume, n + 1, s);
}

void Student::SetNotaMate(float x)
{
	this->notaMate = x;
}


void Student::SetNotaEngleza(float x)
{
	this->notaEngleza = x;
}


void Student::SetNotaIstorie(float x)
{
	this->notaIstorie = x;
}

float Student::GetNotaMate()
{
	return this->notaMate;
}

float Student::GetNotaEngleza()
{
	return this->notaEngleza;
}

float Student::GetNotaIstorie()
{
	return this->notaIstorie;
}

float Student::media()
{
	float s = notaEngleza + notaIstorie + notaMate;
	s = s / 3;
	return s;
}
