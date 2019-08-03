#include <cstdio>
#include <algorithm>
using namespace std;

int A[1001];
int d[1001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		for (int j = 1; j < i; j++)
			if (A[j] < A[i]) temp = max(temp, d[j]);
		d[i] = temp + 1;
		if (num < d[i]) num = d[i];
	}

	printf("%d\n", num);
	return 0;
}