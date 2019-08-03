#include <cstdio>

long long d[91][2];

int main(void)
{
	int N;
	scanf("%d", &N);

	d[1][0] = 1; d[1][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}

	printf("%lld\n", d[N][1]);
	return 0;
}