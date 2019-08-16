#include <iostream>
#include <queue>

using namespace std;

char map[101][101];
bool checkMap[101][101];
int valueMap[101][101];
int tempW, tempH;

int movX[] = { 0, 0, -1, 1 };
int movY[] = { -1, 1, 0, 0 };
void bfs()
{
	int cnt = 1;

	queue<pair<int, int>> tempQ;
	tempQ.push(make_pair(0,0));
	checkMap[0][0] = true;
	valueMap[0][0] = cnt;

	while (!tempQ.empty())
	{
		int x = tempQ.front().first;
		int y = tempQ.front().second;
		cnt = valueMap[x][y];
		tempQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int tempX = x + movX[i];
			int tempY = y + movY[i];

			if (0 <= tempX && tempX < tempH && 0 <= tempY && tempY < tempW)
			{
				if (map[tempX][tempY] == '1' && !checkMap[tempX][tempY])
				{
					tempQ.push(make_pair(tempX, tempY));
					checkMap[tempX][tempY] = true;
					valueMap[tempX][tempY] = cnt +1;
				}
			}
		}
	}
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    
	cin >> tempH >> tempW;

	for (int i = 0; i < tempH; ++i)
	{
		cin >> map[i];
	}

	bfs();


	cout << valueMap[tempH - 1][tempW - 1] << '\n';

	return 0;
}