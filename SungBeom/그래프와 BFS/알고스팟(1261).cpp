#include <iostream>
#include <deque>
using namespace std;

int maze[100][100];
int breakCount[100][100];
bool check[100][100];

int nx[] = { -1, 1, 0, 0 };
int ny[] = { 0, 0, -1, 1 };

int M, N;

bool inRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main(void)
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &maze[i][j]);

	deque<pair<int, int>> d;
	check[0][0] = true; d.push_back(make_pair(0, 0));
	while (!d.empty())
	{
		pair<int, int> current = d.front(); d.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int x = current.first + nx[i], y = current.second + ny[i];
			if (inRange(x, y) && !check[x][y])
			{
				if (maze[x][y] == 0)
				{
					check[x][y] = true; d.push_front(make_pair(x, y));
					breakCount[x][y] = breakCount[current.first][current.second];
				}
				else
				{
					check[x][y] = true; d.push_back(make_pair(x, y));
					breakCount[x][y] = breakCount[current.first][current.second] + 1;
				}
			}
		}
	}

	printf("%d\n", breakCount[N - 1][M - 1]);
	return 0;
}