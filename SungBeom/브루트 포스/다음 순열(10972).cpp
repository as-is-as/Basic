#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> p(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	if (next_permutation(p.begin(), p.end()))
		for (int i = 0; i < n; i++)
			printf("%d ", p[i]);
	else
		printf("%d", -1);
	printf("\n");

	return 0;
}