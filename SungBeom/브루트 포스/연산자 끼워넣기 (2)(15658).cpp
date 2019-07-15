#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <set>
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
	int nums[11], operatorCount[4];
	vector<int> operators;
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &operatorCount[i]);
		for (int j = 0; j < operatorCount[i]; j++)
			operators.push_back(i);
	}

	vector<int> p(operators.size());
	for (int i = 0; i < N - 1; i++) p[i] = 1;
	for (int i = N - 1; i < operators.size(); i++) p[i] = 0;

	set<string> check;
	long min = LONG_MAX, max = LONG_MIN;
	do
	{
		vector<int> p2;
		string op = "";
		for (int i = 0; i < operators.size(); i++)
			if (p[i] == 1)
			{
				p2.push_back(operators[i]);
				op += to_string(operators[i]);
			}

		pair<set<string>::iterator, bool> pr = check.insert(op);
		if (pr.second == false) continue;

		do
		{
			long num = nums[0];
			for (int i = 0; i < N - 1; i++)
				nextNum(num, nums[i + 1], p2[i]);

			if (min > num) min = num;
			if (max < num) max = num;
		} while (next_permutation(p2.begin(), p2.end()));
	} while (prev_permutation(p.begin(), p.end()));

	printf("%d\n%d\n", max, min);
	return 0;
}