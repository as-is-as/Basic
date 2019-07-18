#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int nums[11], operators[4];
vector<int> p;

void calcNum(long& num, int index)
{
	if (index == N - 1) return;
	else if (p[index] == 0) num += nums[index + 1];
	else if (p[index] == 1) num -= nums[index + 1];
	else if (p[index] == 2) num *= nums[index + 1];
	else if (p[index] == 3) num /= nums[index + 1];

	calcNum(num, index + 1);
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &operators[i]);

	int index = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < operators[i]; j++)
			p.push_back(i);

	long min = LONG_MAX, max = LONG_MIN;
	do
	{
		long num = nums[0];
		calcNum(num, 0);

		if (min > num) min = num;
		if (max < num) max = num;
	} while (next_permutation(p.begin(), p.end()));

	printf("%d\n%d\n", max, min);
	return 0;
}