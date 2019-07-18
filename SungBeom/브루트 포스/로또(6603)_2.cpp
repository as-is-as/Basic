#include <iostream>
#include <vector>
using namespace std;

int k;
int nums[13];

void lotto(vector<int>& lottoNums, int index)
{
	if (lottoNums.size() == 6)
	{
		for (int i = 0; i < 6; i++)
			printf("%d ", lottoNums[i]);
		printf("\n");
		return;
	}
	if (index >= k) return;

	lottoNums.push_back(nums[index]);
	lotto(lottoNums, index + 1);
	lottoNums.pop_back();
	lotto(lottoNums, index + 1);
}

int main(void)
{
	while (true)
	{
		scanf("%d", &k);
		if (k == 0) break;

		for (int i = 0; i < k; i++)
			scanf("%d", &nums[i]);

		vector<int> lottoNums;
		lotto(lottoNums, 0);
		printf("\n");
	}

	return 0;
}