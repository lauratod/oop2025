#include "canvas.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	canvas ob1(30,15),ob2(30,15),ob3(30,15);
	ob1.FillCircle(10, 7, 5, '0');
	ob1.Print();
	ob1.Clear();
	ob1.DrawRect(3,7,10,10,'0');
	ob1.SetPoint(7, 3, '.');
	ob1.Print();
	ob3.DrawLine(0, 1, 6, 4, '.');
	ob3.Print();
	return 0;
}