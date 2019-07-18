#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

void nextNum(long& num, int& operand, int& op)
{
	switch (op)
	{
	case 0:
		num += operand;
		break;
	case 1:
		num -= operand;
		break;
	case 2:
		num *= operand;
		break;
	case 3:
		num /= operand;
		break;
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	int nums[11], operators[4];
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &operators[i]);

	vector<int> p(N - 1);
	int index = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < operators[i]; j++)
			p[index++] = i;

	long min = LONG_MAX, max = LONG_MIN;
	do
	{
		long num = nums[0];
		for (int i = 0; i < N - 1; i++)
			nextNum(num, nums[i + 1], p[i]);

		if (min > num) min = num;
		if (max < num) max = num;
	} while (next_permutation(p.begin(), p.end()));

	printf("%d\n%d\n", max, min);
	return 0;
}