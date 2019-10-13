#include <iostream>
#include <vector>
using namespace std;

vector<int> v[20001];
int check[20001];

void dfs(int num, int c)
{
	check[num] = c;
	
	for (int i = 0; i < v[num].size(); ++i)
	{
		int next = v[num][i];
		if (check[next] == 0)
		{
			dfs(next, 3-c);
		}
	}
}
int main()
{
	int a;
	cin >> a;
	while (a--)
	{
		int b, c;
		cin >> b >> c;
		for (int i = 1; i <= b; ++i)
		{
			v[i].clear();
			check[i] = 0;
		}

		for (int i = 1; i <= c; ++i)
		{
			int d, e;
			cin >> d >> e;
			v[d].push_back(e);
			v[e].push_back(d);
		}

		for (int i = 1; i <= b; ++i)
		{
			if (check[i] == 0)
			{
				dfs(i, 1);
			}
		}

		bool ok = true;

		for (int i = 1; i <= b; ++i)
		{
			for (int k = 0; k < v[i].size(); k++)
			{
				int j = v[i][k];
				if (check[i] == check[j])
				{
					ok = false;
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}