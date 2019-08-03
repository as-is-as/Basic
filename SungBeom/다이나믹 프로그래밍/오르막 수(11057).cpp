#include <cstdio>

int d[1001][10];

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++) d[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
				d[i][j] += d[i - 1][k];
			d[i][j] %= 10007;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += d[N][i];
		result %= 10007;
	}
	printf("%d\n", result);
	return 0;
}