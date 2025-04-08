#pragma once
class Number
{
	char* nr;
	int base, length;
public:

	Number();//default constructor-construieste numarul 0 in baza 10
	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& n); // copy constructor
	Number(Number&& n);// move constructor
	Number(int x);
	~Number();

	Number& operator=(const Number& n);
	Number& operator=(const char* val);
	Number& operator=(int val);

	int chartoint(char c)const;
	char inttochar(int c)const;
	int tobaza10()const;
	void frombaza10(int x, int b);


	bool operator==(const Number& n)const;
	bool operator!=(const Number& n)const;
	bool operator<(const Number& n)const;
	bool operator<=(const Number& n)const;
	bool operator>(const Number& n)const;
	bool operator>=(const Number& n)const;
	char operator[](int index);
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	Number& operator--();//++n prefix
	Number operator--(int);//n++ postfix
	Number& operator+=(const Number& n);


	void SwitchBase(int b);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
