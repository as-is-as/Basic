#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[2001];
bool check[2001];
bool check2 = false;

void dfs(int num, int count)
{
	check[num] = true;

	if (count == 5)
	{
		check2 = true;
		return;
	}

	for (int i = 0; i < v[num].size(); i++)
	{
		int next = v[num][i];

		if (check[next] == false)
		{
			dfs(next, count + 1);
		}
	}
	check[num] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	for (int i = 0; i < b; i++)
	{
		int c, d;
		cin >> c >> d;

		v[c].push_back(d);
		v[d].push_back(c);
	}

	for (int i = 0; i < a; i++)
	{
		memset(check, false, sizeof(check));
		dfs(i, 1);

		if (check2 == true)
		{
			break;
		}
	}

	if (check2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

	return 0;
}