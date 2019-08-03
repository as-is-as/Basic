#include <cstdio>
#include <climits>

int d[100001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) d[i] = INT_MAX;
	for (int i = 1; i*i <= n; i++) d[i*i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i / 2; j++)
			if (d[i] > d[j] + d[i - j]) d[i] = d[j] + d[i - j];

	printf("%d\n", d[n]);
	return 0;
}