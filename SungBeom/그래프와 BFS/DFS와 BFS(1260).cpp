#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	vector<vector<int>> graph(N + 1);
	vector<bool> check(N + 1, false);

	while (M--)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	stack<int> s;
	s.push(V);
	while (!s.empty())
	{
		int current = s.top(); s.pop();
		if (check[current] == true) continue;
		check[current] = true;
		printf("%d ", current);
		for (int i = graph[current].size() - 1; i >= 0; i--)
		{
			int next = graph[current][i];
			if (check[next] == false) s.push(next);
		}
	}
	printf("\n");

	for (int i = 1; i <= N; i++) check[i] = false;

	queue<int> q;
	check[V] = true; q.push(V);
	while (!q.empty())
	{
		int current = q.front(); q.pop();
		printf("%d ", current);
		for (int i = 0; i < graph[current].size(); i++)
		{
			int next = graph[current][i];
			if (check[next] == false) { check[next] = true; q.push(next); }
		}
	}
	printf("\n");

	return 0;
}