#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> graph(N + 1);
	vector<bool> check(N + 1, false);

	while (M--)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	stack<int> s;
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (check[i] == true) continue;
		
		s.push(i); count++;
		while (!s.empty())
		{
			int current = s.top(); s.pop();
			if (check[current] == true) continue;
			check[current] = true;
			for (int i = graph[current].size() - 1; i >= 0; i--)
			{
				int next = graph[current][i];
				if (check[next] == false) s.push(next);
			}
		}
	}

	printf("%d\n", count);
	return 0;
}