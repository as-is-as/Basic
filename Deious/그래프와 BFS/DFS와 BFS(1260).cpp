#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int num)
{
	check[num] = true;
	printf("%d ", num);
	for(int i =0; i<a[num].size(); ++i)
	{
		int next = a[num][i];
		if (check[next] == false)
		{
			dfs(next);
		}
	}
}

void bfs(int num)
{
	queue<int> q;
	memset(check, false, sizeof(check));
	check[num] = true;
	q.push(num);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i < a[node].size(); ++i)
		{
			int next = a[node][i];
			if (check[next] == false)
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m, start;
	cin >> n >> m >> start;
	for (int i = 0; i < m; ++i) 
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	puts("");
	bfs(start);
	puts("");
	return 0; 
}