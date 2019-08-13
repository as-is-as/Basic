#include <cstdio>

long d[1000001];

int main(void)
{
	int T;
	scanf("%d", &T);

	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;

	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}

	return 0;
}