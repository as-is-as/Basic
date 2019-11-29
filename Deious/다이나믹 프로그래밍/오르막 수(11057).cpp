#include <iostream>

using namespace std;

int check[1001][10];

int main()
{
	int a;
	long long ans = 0;

	cin >> a;

	for (int i = 0; i <= 9; i++)
	{
		check[1][i] = 1;
	}

	for (int i = 2; i <= a; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				check[i][j] += check[i - 1][k];
				check[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		ans += check[a][i];
	}
	cout << ans % 10007;

	return 0;
}