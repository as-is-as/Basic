#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int box[1001][1001];
int check[1001][1001];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N, M;

int Max() 
{
	int maxnum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0)
			{
				return -1;
			}
			else if (check[i][j] > maxnum)
			{
				maxnum = check[i][j];
			}
		}
	}
	return maxnum;
}

int main() {

	queue<pair<int, int>> q;
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			scanf("%d", &box[i][j]);
		}
	}

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			if (box[i][j] == 1 && check[i][j] == 0)
			{
				q.push(make_pair(i, j));
				check[i][j] = 0;
			}
		}
	}

	int x, y;

	while (!q.empty()) 
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) 
			{
				if (box[nx][ny] == 0 & check[nx][ny] == 0) 
				{
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
					box[nx][ny] = 1;
				}

				else if (box[nx][ny] == -1 && check[nx][ny] == 0) 
				{
					check[nx][ny] = -1;
				}
			}
		}

	}
	printf("%d", Max());

	return 0;
}