#include <iostream>

using namespace std;

long long check[1000001];

int main()
{
	int a,b;
	check[0] = 1;
	scanf("%d", &a);

	for (int i = 1; i <= 1000000; i++)
	{
		if (i - 1 >= 0)
		{
			check[i] += check[i - 1];
		}
		if (i - 2 >= 0)
		{
			check[i] += check[i - 2];
		}
		if (i - 3 >= 0)
		{
			check[i] += check[i - 3];
		}
		check[i] %= 1000000009;
	}

	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		printf("%lld\n", check[b]);
	}
	return 0;
}