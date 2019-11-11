#include <iostream>

using namespace std;

long long check[100001][4];

int main()
{
	int a, b;
	scanf("%d", &a);

	for (int i = 1; i <= 100000; i++)
	{
		if (i - 1 >= 0)
		{
			if (i == 1)
			{
				check[i][1] = 1;
			}
			else
			{
				check[i][1] = check[i - 1][2] + check[i-1][3];
			}
		}
		if (i - 2 >= 0)
		{
			if (i == 2)
			{
				check[i][2] = 1;
			}
			else
			{
				check[i][2] = check[i - 2][1] + check[i - 2][3];
			}
		}
		if (i - 3 >= 0)
		{
			if (i == 3)
			{
				check[i][3] = 1;
			}
			else
			{
				check[i][3] = check[i - 3][1] + check[i - 3][2];
			}
		}
		check[i][1] %= 1000000009;
		check[i][2] %= 1000000009;
		check[i][3] %= 1000000009;
	}

	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		printf("%lld\n", (check[b][1] + check[b][2] + check[b][3])% 1000000009);
	}
	return 0;
}