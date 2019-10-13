#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[50][50];
bool check[50][50];
int mx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int my[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int a, b;
int cnt = 0;
vector<int> v;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int tempX = x + mx[i];
			int tempY = y + my[i];

			if (tempX >= 0 && tempY >= 0 && tempX < b && tempY < a)
			{
				if (map[tempX][tempY] == 1 && check[tempX][tempY] == false)
				{
					q.push(make_pair(tempX, tempY));
					check[tempX][tempY] = true;
				}
			}
		}
	}
}

int main()
{
	while (true)
	{
		cnt = 0;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				if (map[i][j] == 1 && check[i][j] == false)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);

		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				map[i][j] = 0;
				check[i][j] = false;
			}
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	return 0;
}