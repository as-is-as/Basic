#include <cstdio>

long d[100001][3];

int main(void)
{
	int T;
	scanf("%d", &T);

	d[1][0] = 1; d[2][1] = 1; d[3][0] = 1; d[3][1] = 1; d[3][2] = 1;
	for (int i = 4; i <= 100000; i++)
	{
		d[i][0] = (d[i - 1][1] + d[i - 1][2]) % 1000000009;
		d[i][1] = (d[i - 2][0] + d[i - 2][2]) % 1000000009;
		d[i][2] = (d[i - 3][0] + d[i - 3][1]) % 1000000009;
	}

	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%ld\n", (d[n][0] + d[n][1] + d[n][2]) % 1000000009);
	}

	return 0;
}