#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s[256], *x,a[51][51], *context, auxiliar[51];
	int n,k=0,v[51],ok,aux;
	//scanf_s("%255s", s, (unsigned)_countof(s));
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = 0;
	x = strtok_s(s, " ", &context);
	while (x)
	{
		n = strlen(x);
		strcpy_s(a[++k],sizeof(a[k]), x);
		v[k] = n;
		x = strtok_s(NULL, " ", &context);
	}
	do
	{
		ok = 0;
		for (int i = 1; i <= k - 1; i++)
		{
			if (v[i] < v[i + 1])
			{
				ok = 1;
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				strcpy_s(auxiliar,sizeof(auxiliar), a[i]);
				strcpy_s(a[i], sizeof(a[i]), a[i + 1]);
				strcpy_s(a[i + 1], sizeof(a[i+1]), auxiliar);
			}
			else if (v[i] == v[i + 1] && strcmp(a[i], a[i + 1]) > 0)
			{
				ok = 1;
				
				
					strcpy_s(auxiliar, sizeof(auxiliar), a[i]);
					strcpy_s(a[i], sizeof(a[i]), a[i + 1]);
					strcpy_s(a[i + 1], sizeof(a[i + 1]), auxiliar);
				
			}
		}
	} while (ok);
	for (int i = 1; i <= k; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}