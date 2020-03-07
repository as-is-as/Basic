#include <cstdio>
#include <queue>

using namespace std;

int map[100][100];
int result[100][100];
bool check[100][100];
int maxX, maxY;

int mx[] = { 1, 0, -1, 0 };
int my[] = { 0, 1, 0, -1 };

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

			if (tempX >= 0 && tempY >= 0 && tempX < maxX && tempY < maxY)
			{
				if (map[tempX][tempY] == 1 && check[tempX][tempY] == false)
				{
					q.push(make_pair(tempX, tempY));
					check[tempX][tempY] = true;
					result[tempX][tempY] = result[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &maxX, &maxY);

	for (int i = 0; i < maxX; ++i)
	{
		for (int j = 0; j < maxY; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	
	bfs(0,0,0);

	printf("%d\n", result[maxX - 1][maxY - 1] + 1);
	return 0;
}