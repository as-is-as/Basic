#include <cstdio>
#include <algorithm>
using namespace std;

int d[2][100001];

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &d[i][j]);

		d[0][2] += d[1][1]; d[1][2] += d[0][1];
		for (int i = 3; i <= n; i++)
			for (int j = 0; j < 2; j++)
				d[j][i] += max(d[(j + 1) % 2][i - 1], max(d[(j + 1) % 2][i - 2], d[j][i - 2]));

		printf("%d\n", max(d[0][n], d[1][n]));
	}

	return 0;
}