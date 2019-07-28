#include <iostream>
#include <queue>
using namespace std;

int warehouse[1000][1000];
bool check[1000][1000];

int nx[] = { -1, 0, 1, 0 };
int ny[] = { 0, -1, 0, 1 };

int M, N;

bool inRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main(void)
{
	scanf("%d %d", &M, &N);

	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &warehouse[i][j]);
			if (warehouse[i][j] == 1) { check[i][j] = true; q.push(make_pair(i, j)); }
		}

	int max = 0;
	while (!q.empty())
	{
		pair<int, int> current = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = current.first + nx[i], y = current.second + ny[i];
			if (inRange(x, y) && check[x][y] == false && warehouse[x][y] == 0)
			{
				check[x][y] = true; q.push(make_pair(x, y));
				warehouse[x][y] = warehouse[current.first][current.second] + 1;
				if (max < warehouse[x][y] - 1) max = warehouse[x][y] - 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (warehouse[i][j] == 0) max = -1;

	printf("%d\n", max);
	return 0;
}