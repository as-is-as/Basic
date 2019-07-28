// w, h
// h줄 지도, 1, 0

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char map[50][50];
char checkMap[50][50];
int movX[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int movY[] = { 1, -1, 0, 0,  1, -1, -1, 1 };
int inputW, inputH;

void bfs(int x, int y)
{
	queue<pair<int, int>> tempQ;
	tempQ.push(make_pair(x, y));
	checkMap[x][y] = true;

	while (!tempQ.empty())
	{
		x = tempQ.front().first;
		y = tempQ.front().second;
		tempQ.pop();

		for (int i = 0; i < 8; ++i)
		{
			int tempX = x + movX[i];
			int tempY = y + movY[i];

			if (0 <= tempX && tempX < inputH && 0 <= tempY && tempY < inputW)
			{
				if (map[tempX][tempY] == '1' && !checkMap[tempX][tempY])
				{
					tempQ.push(make_pair(tempX, tempY));
					checkMap[tempX][tempY] = true;
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	while (true)
	{
		int cnt = 0;
		cin >> inputW >> inputH;

		if (inputW == 0 && inputH == 0)
			break;

		for (int i = 0; i < inputH; ++i)
		{
			for (int j = 0; j < inputW; ++j)
			{
				cin >> map[i][j];
			}
		}
		//bfs
		for (int i = 0; i < inputH; ++i)
		{
			for (int j = 0; j < inputW; ++j)
			{
				if (map[i][j] == '1' && !checkMap[i][j])
				{
					bfs(i, j);
					++cnt;
				}
			}
		}
		cout << cnt << '\n';
		//초기화
		for (int i = 0; i < inputH; ++i)
		{
			for (int j = 0; j < inputW; ++j)
			{
				map[i][j] = '0';
				checkMap[i][j] = false;
			}
		}
	}
	return 0;
}