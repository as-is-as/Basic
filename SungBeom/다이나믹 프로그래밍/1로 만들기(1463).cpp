#include <cstdio>
#include <algorithm>
using namespace std;

int d[1000001];

int main(void)
{
	int N;
	scanf("%d", &N);

	d[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (i % 3 == 0 && i % 2 == 0) d[i] = min(d[i - 1], min(d[i / 2], d[i / 3])) + 1;
		else if (i % 3 == 0) d[i] = min(d[i - 1], d[i / 3]) + 1;
		else if (i % 2 == 0) d[i] = min(d[i - 1], d[i / 2]) + 1;
		else d[i] = d[i - 1] + 1;
	}

	printf("%d\n", d[N]);
	return 0;
}