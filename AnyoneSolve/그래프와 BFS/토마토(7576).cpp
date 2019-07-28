#include <iostream>
#include <queue>

using namespace std;


int map[1001][1001];
bool checkMap[1001][1001];
int valueMap[1001][1001];

int N, M;

int movX[] = { 0, 0, -1, 1 };
int movY[] = { -1, 1, 0, 0 };

queue<pair<int, int>> tempQ;

void bfs()
{
	while (!tempQ.empty())
	{
		int x = tempQ.front().first;
		int y = tempQ.front().second;
		int cnt = valueMap[x][y];
		tempQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int tempX = x + movX[i];
			int tempY = y + movY[i];

			if (0 <= tempX && tempX < N && 0 <= tempY && tempY < M)
			{
				if (map[tempX][tempY] == 0 && !checkMap[tempX][tempY])
				{
					tempQ.push(make_pair(tempX, tempY));
					checkMap[tempX][tempY] = true;
					valueMap[tempX][tempY] = cnt + 1;
				}
			}
		}
	}
}
void checkMax()
{
	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (valueMap[i][j] == 0)
			{
				cout << "-1\n";
				return;
			}
			max = max < valueMap[i][j] ? valueMap[i][j] : max;			
		}
	}
	cout << max - 1 << '\n';
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> M >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == -1)
			{
				valueMap[i][j] = -1;
				valueMap[i][j] = true;
			}
			if (map[i][j] == 1 && !checkMap[i][j])
			{
				tempQ.push(make_pair(i, j));
				checkMap[i][j] = true;
				valueMap[i][j] = 1;
			}
		}
	}

	bfs();
	checkMax();

	return 0;
}