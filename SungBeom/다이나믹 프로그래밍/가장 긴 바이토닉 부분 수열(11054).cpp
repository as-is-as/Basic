#include <cstdio>
#include <algorithm>
using namespace std;

int A[1001];
int d1[1001], d2[1001];

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
			if (A[j] < A[i]) temp = max(temp, d1[j]);
		d1[i] = temp + 1;
	}
	for (int i = N; i >= 1; i--)
	{
		int temp = 0;
		for (int j = N; j >= i; j--)
			if (A[j] < A[i]) temp = max(temp, d2[j]);
		d2[i] = temp + 1;
	}
	for (int i = 1; i <= N; i++)
		if (num < d1[i] + d2[i]) num = d1[i] + d2[i];

	printf("%d\n", num - 1);
	return 0;
}