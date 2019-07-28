#include <iostream>
#include <queue>
using namespace std;

int maze[100][100];
bool check[100][100];

int nx[] = { -1, 0, 1, 0 };
int ny[] = { 0, -1, 0, 1 };

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

	queue<pair<int, int>> q;
	bool finish = false;
	check[0][0] = true; q.push(make_pair(0, 0));
	while (!q.empty())
	{
		pair<int, int> current = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = current.first + nx[i], y = current.second + ny[i];
			if (inRange(x, y) && check[x][y] == false && maze[x][y])
			{
				check[x][y] = true; q.push(make_pair(x, y));
				maze[x][y] = maze[current.first][current.second] + 1;
			}
			if (x == N - 1 && y == M - 1) { finish = true; break; }
		}
		if (finish) break;
	}

	printf("%d\n", maze[N - 1][M - 1]);
	return 0;
}