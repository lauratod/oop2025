#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList v;
	v.Init();
	v.Add(10);
	v.Add(7);
	v.Add(11);
	v.Add(90);
	v.Add(4);
	v.Sort();
	v.Print();
	return 0;
}