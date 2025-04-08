#include <stdio.h>
#include <stdlib.h>

using namespace std;

float operator"" _Kelvin(long double x)
{
    return x + 273.15;
}

float operator"" _Fahrenheit(long double x)
{
    return (x * 1.8) + 32;
}

int main()
{
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    printf("a= %.2f Kelvin \n", a);
    printf("b= %.2f Fahrenheit \n", b);
    return 0;
}