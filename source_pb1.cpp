#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int convertchar(char s[])
{
	int n = strlen(s),x=0, c, p = 1;
    if (s[n - 1] == '\n')
    {
        s[n - 1] = NULL;
        n--;
    }
	for (int i = n - 1; i >= 0; i--)
	{
		c = s[i] - '0';
		x = x + c * p;
		p *= 10;
	}
	return x;
}
int main()
{
    FILE* file;
    errno_t err=fopen_s(&file, "ini.txt", "r");
    if (err != 0 || file == NULL) {
        printf("eroare: nu s a putut deschide fisierul!\n");
        return 1;
    }
    char line[11]; 
    long long sum = 0;

    while (fgets(line, sizeof(line), file)) {
        sum += convertchar(line); 
    }

    fclose(file);

    printf("%lld\n", sum); // Print the sum

    return 0;
}
