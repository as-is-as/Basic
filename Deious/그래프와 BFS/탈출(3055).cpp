#include<iostream>
#include<queue>

using namespace std;

int waterMap[51][51];
char escapeMap[51][51];
bool visit[51][51];
bool check;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0};

int main()
{
	int r, c;
	queue<pair<pair<int, int>, int>> q;
	queue<pair<int, int>> q1;

	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf(" %c", &escapeMap[i][j]);
			waterMap[i][j] = 9999;

			if (escapeMap[i][j] == 'S')
			{
				q.push(make_pair(make_pair(i, j), 0));
			}
			else if (escapeMap[i][j] == '*')
			{
				q1.push(make_pair(i, j));
				waterMap[i][j] = 0;
			}
		}
	}

	while (!q1.empty())
	{
		int x = q1.front().first;
		int y = q1.front().second;
		q1.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > r || ny < 1 || ny > c || escapeMap[nx][ny] == 'D' || escapeMap[nx][ny] == 'X') continue;

			if (escapeMap[nx][ny] == '.' && waterMap[nx][ny] > waterMap[x][y])
			{
				waterMap[nx][ny] = waterMap[x][y] + 1;
				q1.push(make_pair(nx, ny));
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int moveCount = q.front().second;
		visit[x][y] = true;

		q.pop();

		if (escapeMap[x][y] == 'D')
		{
			printf("%d", moveCount);
			check = true;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > r || ny < 1 || ny > c || escapeMap[nx][ny] == 'X') continue;

			if ((escapeMap[nx][ny] == 'D' || escapeMap[nx][ny] == '.') && moveCount < waterMap[nx][ny] - 1 && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), moveCount + 1));
			}
		}
	}

	if (!check)
	{
		printf("%s", "KAKTUS");
	}

	return 0;
}