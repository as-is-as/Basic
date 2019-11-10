#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char d[25][25];
bool check[25][25];

int mx[] = { 0, 0, 1, -1 };
int my[] = { 1, -1, 0, 0 };
int n = 0;

vector<int> v;

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int tempX = x + mx[i];
			int tempY = y + my[i];

			if (tempX >= 0 && tempY >= 0 && tempX < n && tempY < n)
			{
				if (d[tempX][tempY] == '1' && check[tempX][tempY] == false)
				{
					q.push(make_pair(tempX, tempY));
					check[tempX][tempY] = true;
					cnt++;
				}
			}
		}
	}
	v.push_back(cnt);
}

int main()
{
	cin >> n;
	int cnt = 0;
	char a = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a;
			d[i][j] = a;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (d[i][j] == '1' && check[i][j] == false)
			{
				bfs(i, j, cnt + 1);
			}
		}
	}

	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	return 0;
}