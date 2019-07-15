#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	scanf("%d", &N);
	vector<int> p(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);
	sort(p.begin(), p.end());

	int max = 0;
	do {
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			int num = p[i] - p[i + 1];
			if (num < 0) sum -= num;
			else sum += num;
		}
		if (max < sum)max = sum;
	} while (next_permutation(p.begin(), p.end()));

	printf("%d\n", max);
	return 0;
}