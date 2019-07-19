#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> sequence;

void printSequence(vector<int>& nums, int M)
{
	if (M == 0)
	{
		for (int i = 0; i < nums.size(); i++)
			printf("%d ", nums[i]);
		printf("\n");
		return;
	}

	vector<int>::iterator iter;
	for (int i = 0; i < N; i++)
	{
		iter = find(nums.begin(), nums.end(), sequence[i]);
		if (iter != nums.end()) continue;

		nums.push_back(sequence[i]);
		printSequence(nums, M - 1);
		nums.pop_back();
	}
}

int main(void)
{
	int M;
	scanf("%d %d", &N, &M);
	sequence.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &sequence[i]);
	sort(sequence.begin(), sequence.end());

	vector<int> nums;
	printSequence(nums, M);

	return 0;
}