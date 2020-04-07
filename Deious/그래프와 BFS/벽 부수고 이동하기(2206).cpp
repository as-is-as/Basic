#include<iostream>
#include<tuple>
#include<deque>

using namespace std;

int n, m;
int nmMap[1001][1001];
int check[1001][1001];
bool visit[1001][1001];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Bfs()
{
	deque<pair<pair<int, int>, int>> d;
	d.push_back(make_pair(make_pair(1,1), 0));
	check[1][1] = 1;
	visit[1][1] = true;

	while (!d.empty())
	{
		int x = d.front().first.first;
		int y = d.front().first.second;
		int breakWall = d.front().second;
		d.pop_front();

		if (x == n && y == m)
		{
			return check[n][m];
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > n || nx < 1 || ny > m || ny < 1) continue;

			if (!visit[nx][ny])
			{
				if (nmMap[nx][ny] == 0)
				{
					visit[nx][ny] = true;
					check[nx][ny] = check[x][y] + 1;
					d.push_front(make_pair(make_pair(nx, ny), 0));
				}
				else
				{
					if (breakWall == 0)
					{
						visit[nx][ny] = true;
						check[nx][ny] = check[x][y] + 1;
						d.push_back(make_pair(make_pair(nx, ny), 1));
					}
				}
			}
		}
	}

	return -1;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &nmMap[i][j]);
		}
	}

	printf("%d", Bfs());

	return 0;
}