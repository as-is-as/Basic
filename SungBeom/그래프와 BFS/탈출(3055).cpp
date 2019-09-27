#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int floodMap[50][50];

int nx[] = { -1, 1, 0, 0 };
int ny[] = { 0, 0, -1, 1 };

int R, C;

bool inRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

int main(void)
{
	scanf("%d %d", &R, &C);

	queue<pair<int, int>> hedgehog, flood;
	pair<int, int> goal;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			scanf(" %c", &map[i][j]);
			floodMap[i][j] = map[i][j];
			if (map[i][j] == '.') map[i][j] = -1;
			else if (map[i][j] == 'X') map[i][j] = -2;
			else if (map[i][j] == '*') { flood.push(make_pair(i, j)); floodMap[i][j] = 0; }
			else if (map[i][j] == 'S') { hedgehog.push(make_pair(i, j)); map[i][j] = 0; }
			else if (map[i][j] == 'D') { goal = make_pair(i, j); map[i][j] = -3; }
		}

	while (!flood.empty())
	{
		pair<int, int> current = flood.front(); flood.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = current.first + nx[i], y = current.second + ny[i];
			if (inRange(x, y) && (floodMap[x][y] == '.' || floodMap[x][y] == 'S'))
			{
				flood.push(make_pair(x, y));
				floodMap[x][y] = floodMap[current.first][current.second] + 1;
			}
		}
	}

	while (!hedgehog.empty())
	{
		pair<int, int> current = hedgehog.front(); hedgehog.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = current.first + nx[i], y = current.second + ny[i];
			if (map[x][y] == -3)
			{
				map[x][y] = map[current.first][current.second] + 1;
				break;
			}
			if (inRange(x, y) && map[x][y] == -1 && (map[current.first][current.second] < floodMap[x][y] - 1 || floodMap[x][y] == '.'))
			{
				hedgehog.push(make_pair(x, y));
				map[x][y] = map[current.first][current.second] + 1;
			}
		}
	}

	if (map[goal.first][goal.second] == -3) printf("KAKTUS\n");
	else printf("%d\n", map[goal.first][goal.second]);
	return 0;
}