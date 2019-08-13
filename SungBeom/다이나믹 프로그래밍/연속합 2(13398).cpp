#include <cstdio>

int nums[100001];
int d1[100001], d2[100002];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &nums[i]);

	for (int i = 1; i <= n; i++)
		if (d1[i - 1] > 0) d1[i] = d1[i - 1] + nums[i];
		else d1[i] = nums[i];
	for (int i = n; i >= 1; i--)
		if (d2[i + 1] > 0) d2[i] = d2[i + 1] + nums[i];
		else d2[i] = nums[i];

	int max = -1001;
	for (int i = 1; i <= n; i++)
		if (max < d1[i]) max = d1[i];
	for (int i = 2; i < n; i++)
		if (max < d1[i - 1] + d2[i + 1]) max = d1[i - 1] + d2[i + 1];

	printf("%d\n", max);
	return 0;
}