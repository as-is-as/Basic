#include <cstdio>

int d[100001];

int main(void)
{
	int n;
	scanf("%d", &n);

	int max = -1001;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		if (d[i - 1] > 0) d[i] += d[i - 1];
		if (max < d[i]) max = d[i];
	}

	printf("%d\n", max);
	return 0;
}