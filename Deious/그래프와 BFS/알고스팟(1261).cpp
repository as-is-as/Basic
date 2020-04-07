#include <iostream>
#include <deque>

using namespace std;

int algoMap[101][101];
int breakCount[101][101];
bool check[101][101];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m;

int Bfs()
{
	deque<pair<int, int>> d;
	d.push_back(make_pair(1, 1));
	check[1][1] = true;

	while (!d.empty())
	{
		int x = d.front().first;
		int y = d.front().second;
		d.pop_front();

		if (x == m && y == n)
		{
			return breakCount[m][n];
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > m || nx < 1 || ny > n || ny < 1) continue;

			if (!check[nx][ny])
			{
				if(algoMap[nx][ny] == 0)
				{
					check[nx][ny] = true;
					breakCount[nx][ny] = breakCount[x][y];
					d.push_front(make_pair(nx, ny));
				}
				else
				{
					check[nx][ny] = true;
					breakCount[nx][ny] = breakCount[x][y] + 1;
					d.push_back(make_pair(nx, ny));
				}
			}
		}
	}

	return 0;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%1d", &algoMap[i][j]);
		}
	}

	printf("%d", Bfs());

	return 0;
}