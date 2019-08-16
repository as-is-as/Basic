#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char map[25][25];
bool checkMap[25][25];

int movX[] = { 0, 0, -1, 1 };
int movY[] = { -1, 1, 0, 0 };

vector<int> tempV;
int inputN;

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>> tempQ;
	tempQ.push(make_pair(x, y));
	checkMap[x][y] = true;

	while (!tempQ.empty())
	{
		x = tempQ.front().first;
		y = tempQ.front().second;	
		tempQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int tempX = x + movX[i];
			int tempY = y + movY[i];
			if (0 <= tempX && tempX < inputN && 0 <= tempY && tempY < inputN)
			{
				if (map[tempX][tempY] == '1' && !checkMap[tempX][tempY])
				{
					tempQ.push(make_pair(tempX, tempY));
					checkMap[tempX][tempY] = true;
					++cnt;
				}
			}
		}
	}
	tempV.push_back(cnt);
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	int cnt = 0;
	int caseCount = 0;
	cin >> inputN;

	for (int i = 0; i < inputN; ++i)
	{
		cin >> map[i];
	}
	
	for (int i = 0; i < inputN; ++i)
	{
		for (int j = 0; j < inputN; ++j)
		{
			if (map[i][j] == '1' && !checkMap[i][j])
			{
				bfs(i, j, cnt + 1);
				++caseCount;
			}
		}
	}

	sort(tempV.begin(), tempV.end());
	
	cout << caseCount << '\n';
	for (int i = 0; i < tempV.size(); ++i)
	{
		cout << tempV[i] << endl;
	}
	return 0;
}