#include <cstdio>
#define div 1000000000

long dp[5001][5001];

int main()
{
	int n, k, max;
	scanf("%d %d", &n, &k);

	if (n > k) max = n;
	else max = k;

	for (int i = 1; i <= max; i++)
	{
		dp[1][i] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= k; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % div;
		}
	}

	printf("%d\n", dp[k][n]);
	return 0;
}