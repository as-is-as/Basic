#include <iostream>

using namespace std;

int check[1000001];

int Min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int main()
{
	check[1] = 0;

	int a;
	scanf("%d", &a);

	for (int i = 2; i <= a; i++)
	{
		check[i] = check[i - 1] + 1;

		if (i % 2 == 0)
		{
			check[i] = Min(check[i], check[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			check[i] = Min(check[i], check[i / 3] + 1);
		}
	}

	printf("%d\n", check[a]);
	return 0;
}