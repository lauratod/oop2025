#pragma once
class Student
{
private:
	char* nume;
	float notaMate;
	float notaEngleza;
	float notaIstorie;

public:
	void SetName(const char* s);
	void SetNotaMate(float x);
	void SetNotaEngleza(float x);
	void SetNotaIstorie(float x);
	const char* GetName() const;
	float GetNotaMate();
	float GetNotaEngleza();
	float GetNotaIstorie();
	float media();

};

