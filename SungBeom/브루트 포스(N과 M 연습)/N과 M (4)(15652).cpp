#include <iostream>
#include <vector>
using namespace std;

int N;

void printSequence(vector<int>& nums, int M)
{
	if (M == 0)
	{
		for (int i = 0; i < nums.size(); i++)
			printf("%d ", nums[i]);
		printf("\n");
		return;
	}

	int start;
	if (nums.size() == 0) start = 1;
	else start = nums[nums.size() - 1];
	for (int i = start; i <= N; i++)
	{
		nums.push_back(i);
		printSequence(nums, M - 1);
		nums.pop_back();
	}
}

int main(void)
{
	int M;
	scanf("%d %d", &N, &M);

	vector<int> nums;
	printSequence(nums, M);

	return 0;
}