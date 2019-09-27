#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int maze[1000][1000];
int moveCount[1000][1000][2];
bool check[1000][1000][2];

int nx[] = { -1, 1, 0, 0 };
int ny[] = { 0, 0, -1, 1 };

int N, M;

bool inRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &maze[i][j]);

	queue<pair<pair<int, int>, int>> q;
	check[0][0][0] = true; q.push(make_pair(make_pair(0, 0), 0));
	moveCount[0][0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first.first, y = q.front().first.second, z = q.front().second; q.pop();
		if (x == N - 1 && y == M - 1) break;

		for (int i = 0; i < 4; i++)
		{
			int xx = x + nx[i], yy = y + ny[i];
			if (inRange(xx, yy) && check[xx][yy][z] == false)
			{
				check[xx][yy][z] = true;
				if (maze[xx][yy] == 0)
				{
					moveCount[xx][yy][z] = moveCount[x][y][z] + 1;
					q.push(make_pair(make_pair(xx, yy), z));
				}
				else if (maze[xx][yy] == 1 && z == 0)
				{
					moveCount[xx][yy][1] = moveCount[x][y][0] + 1;
					q.push(make_pair(make_pair(xx, yy), 1));
				}
			}
		}
	}

	if (moveCount[N - 1][M - 1][0] != 0 && moveCount[N - 1][M - 1][1] != 0)
		printf("%d\n", min(moveCount[N - 1][M - 1][0], moveCount[N - 1][M - 1][1]));
	else if (moveCount[N - 1][M - 1][0] != 0)
		printf("%d\n", moveCount[N - 1][M - 1][0]);
	else if (moveCount[N - 1][M - 1][1] != 0)
		printf("%d\n", moveCount[N - 1][M - 1][1]);
	else printf("-1\n");
	return 0;
}