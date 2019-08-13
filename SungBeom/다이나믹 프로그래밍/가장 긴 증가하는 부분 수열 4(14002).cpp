#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int A[1001];
pair<int, int> d[1001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	pair<int, int> last = make_pair(0, -1);
	for (int i = 1; i <= N; i++)
	{
		pair<int, int> temp = make_pair(0, -1);
		for (int j = 1; j < i; j++)
			if (A[j] < A[i] && temp.first < d[j].first)
				temp = make_pair(d[j].first, j);
		temp.first += 1;
		d[i] = temp;
		if (last.first < d[i].first) last = d[i];
	}

	printf("%d\n", last.first);

	stack<int> result;
	int lastIndex = 1;
	for (int i = 2; i <= N; i++)
		if (d[lastIndex].first < d[i].first) lastIndex = i;
	result.push(A[lastIndex]);

	int index = last.second;
	while (index != -1)
	{
		result.push(A[index]);
		last = d[last.second];
		index = last.second;
	}

	while (!result.empty())
	{
		printf("%d ", result.top());
		result.pop();
	}
	return 0;
}