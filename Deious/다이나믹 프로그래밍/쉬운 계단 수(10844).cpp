#include <iostream>

using namespace std;

int check[101][10];

int main()
{
	int a;
	long long ans = 0;
	//scanf("%d", &a);
	cin >> a;

	for (int i = 1; i <= 9; i++)
	{
		check[1][i] = 1;
	}

	for (int i = 2; i <= a; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			check[i][j] = 0;
			if (j - 1 >= 0)
			{
				check[i][j] += check[i - 1][j - 1];
			}
			if (j + 1 <= 9)
			{
				check[i][j] += check[i - 1][j + 1];
			}
			check[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		ans += check[a][i];
	}
	cout << ans % 1000000000;
	//ans %= 1000000000;
	//printf("%ld", &ans);
}