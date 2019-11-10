#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];
bool check[1001];
int countNum = 0;

void dfs(int num)
{
	check[num] = true;
	for (int i = 0; i < v[num].size(); ++i)
	{
		int next = v[num][i];
		if (check[next] == false)
		{
			dfs(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= b; ++i)
	{
		int c, d;
		cin >> c >> d;
		v[c].push_back(d);
		v[d].push_back(c);
	}

	for (int i = 1; i <= a; ++i) 
	{
		if (check[i])continue;
		dfs(i);
		++countNum;
	}
	cout << countNum;
	return 0;
}