#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> check;

void dfs(int current, int num)
{
	check[current] = num;
	for (int i = 0; i < graph[current].size(); i++)
	{
		int next = graph[current][i];
		if (check[next] == false)
			dfs(next, 3 - num);
	}
}

int main(void)
{
	int K;
	scanf("%d", &K);

	while (K--)
	{
		int V, E;
		scanf("%d %d", &V, &E);
		graph.clear(); graph.resize(V + 1);
		check.clear(); check.resize(V + 1);

		while (E--)
		{
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		for (int i = 1; i <= V; i++)
			if (check[i] == 0) dfs(i, 1);

		bool half = true;
		for (int i = 1; i <= V; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
				if (check[i] == check[graph[i][j]])
				{
					half = false;
					break;
				}
			if (!half) break;
		}

		if (half) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}