#include <cstdio>
#include <algorithm>
using namespace std;

int d[1001];

int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &d[i]);
		for (int j = 1; j <= i / 2; j++)
			d[i] = min(d[i], d[i - j] + d[j]);
	}

	printf("%d\n", d[N]);
	return 0;
}