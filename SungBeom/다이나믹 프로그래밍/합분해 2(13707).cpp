#include <cstdio>

long d[5001][5002];

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) d[1][i] = 1;
	for (int i = 2; i <= K; i++)
		for (int j = 0; j <= N; j++)
		{
			d[i][j] = d[i][j - 1] + d[i - 1][j];
			d[i][j] %= 1000000000;
		}

	printf("%d\n", d[K][N]);
	return 0;
}