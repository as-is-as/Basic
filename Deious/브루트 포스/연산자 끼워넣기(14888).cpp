#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long minNum = 1000000000, maxNum = -1000000000;
int nums[11];

void calcNum(long num, vector<int> &operators, int index)
{
	if (index == n - 1)
	{
		if (minNum > num) minNum = num;
		if (maxNum < num) maxNum = num;

		return;
	}
	else
	{
		if (operators[0] > 0)
		{
			operators[0]--;
			calcNum(num + nums[index + 1], operators, index + 1);
			operators[0]++;
		}
		if (operators[1] > 0)
		{
			operators[1]--;
			calcNum(num - nums[index + 1], operators, index + 1);
			operators[1]++;
		}
		if (operators[2] > 0)
		{
			operators[2]--;
			calcNum(num * nums[index + 1], operators, index + 1);
			operators[2]++;
		}
		if (operators[3] > 0)
		{
			operators[3]--;
			calcNum(num / nums[index + 1], operators, index + 1);
			operators[3]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	vector<int> operators(4);

	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < 4; i++) cin >> operators[i];

	int index = 0;

	long num = nums[0];
	calcNum(num, operators, 0);

	printf("%d\n%d\n", maxNum, minNum);

	return 0;
}