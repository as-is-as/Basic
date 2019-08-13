#include <cstdio>

int d[1001];

int main(void)
{
	int n;
	scanf("%d", &n);

	d[1] = 1; d[2] = 3;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 2] * 2 + d[i - 1]) % 10007;

	printf("%d\n", d[n]);
	return 0;
}