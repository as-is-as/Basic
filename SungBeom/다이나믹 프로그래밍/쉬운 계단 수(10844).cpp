#include <cstdio>

long d[101][10];

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++) d[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		d[i][0] = d[i - 1][1];
		for (int j = 1; j < 9; j++) d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		d[i][9] = d[i - 1][8];
	}

	long result = 0;
	for (int i = 1; i < 10; i++)
	{
		result += d[N][i];
		result %= 1000000000;
	}
	printf("%ld\n", result);
	return 0;
}