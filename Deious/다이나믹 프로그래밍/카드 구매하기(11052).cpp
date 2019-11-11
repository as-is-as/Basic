#include <iostream>

using namespace std;

int check[1001];
int gold[10001];

int Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int a, b;
	scanf("%d", &a);

	for (int i = 1; i <= a; i++)
	{
		scanf("%d", &b);
		gold[i] = b;
	}

	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			check[i] = Max(check[i], check[i - j] + gold[j]);
		}
	}
	printf("%d", check[a]);
	return 0;
}