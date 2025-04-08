#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

int main()
{
	math ob;
	printf("%d\n", ob.Add(5, 1,2,3,4,5));
	printf("%d\n", ob.Mul(5, 6));
    // String concatenation
    char* result = math::Add("cuv1", "cuv2");
    if (result) {
        printf("%s\n", result);
        //delete[] result; // Free allocated memory
    }
    else {
        printf("String concatenation failed!\n");
    }
	return 0;
}