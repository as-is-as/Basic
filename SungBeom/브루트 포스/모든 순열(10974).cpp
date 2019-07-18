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
		p[i] = i + 1;

	do {
		for (int i = 0; i < N; i++)
			printf("%d ", p[i]);
		printf("\n");
	} while (next_permutation(p.begin(), p.end()));

	return 0;
}