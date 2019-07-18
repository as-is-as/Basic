#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, S;
	scanf("%d %d", &N, &S);
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		vector<int> p(N);
		for (int j = 0; j <= i; j++) p[j] = 1;
		for (int j = i + 1; j < N; j++) p[j] = 0;
		
		do
		{
			int sum = 0;
			for (int j = 0; j < N; j++)
				if (p[j] == 1) sum += nums[j];
			if (sum == S) count++;
		} while (prev_permutation(p.begin(), p.end()));
	}

	printf("%d\n", count);
	return 0;
}