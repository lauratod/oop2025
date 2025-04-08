#include "Student.h"
#include "Compara.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	Student st1;
	st1.SetName("raluca");
	st1.SetNotaEngleza(5);
	st1.SetNotaMate(5);
	st1.SetNotaIstorie(10);
	float nota = st1.GetNotaEngleza();
	printf("Nota la engleza este %.2f \n", nota);
	printf("media notelor ralucai este %.2f \n", st1.media());

	Student st2;
	st2.SetName("maria");
	st2.SetNotaEngleza(7);
	st2.SetNotaMate(8);
	st2.SetNotaIstorie(6);
	printf("media notelor mariei este %.2f \n", st2.media());
	printf("comparaMedie dintre raluca si maria : %d \n", comparaMedie(st1, st2));
}