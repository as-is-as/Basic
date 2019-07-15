#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	while (true)
	{
		int k;
		scanf("%d", &k);
		if (k == 0) break;

		vector<int> nums(k), p(k);
		for (int i = 0; i < k; i++)
			scanf("%d", &nums[i]);

		for (int i = 0; i < 6; i++) p[i] = 1;
		for (int i = 6; i < k; i++) p[i] = 0;

		do
		{
			for (int i = 0; i < k; i++)
				if (p[i] == 1) printf("%d ", nums[i]);
			printf("\n");
		} while (prev_permutation(p.begin(), p.end()));
		printf("\n");
	}

	return 0;
}