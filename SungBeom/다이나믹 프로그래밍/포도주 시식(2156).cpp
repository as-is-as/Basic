#include <cstdio>
#include <algorithm>
using namespace std;

int wine[10001];
int d[10001][3];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &wine[i]);

	d[1][0] = 0; d[1][1] = wine[1]; d[1][2] = wine[1];
	d[2][0] = 0; d[2][1] = wine[2]; d[2][2] = wine[1] + wine[2];
	d[3][0] = wine[1] + wine[2];
	d[3][1] = wine[1] + wine[3];
	d[3][2] = wine[2] + wine[3];

	for (int i = 4; i <= n; i++)
	{
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + wine[i];
		d[i][2] = d[i - 1][1] + wine[i];
	}

	printf("%d\n", max(d[n][0], max(d[n][1], d[n][2])));
	return 0;
}