#include <iostream>
#include <queue>
using namespace std;

char map[50][50];
char floodMap[50][50];

int nx[] = { -1, 1, 0, 0 };
int ny[] = { 0, 0, -1, 1 };

int R, C;

bool inRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

int main(void)
{
	scanf("%d %d", &R, &C);

	queue<pair<int, int>> hedgehog, flood;
	pair<int, int> goal;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			scanf(" %c", &map[i][j]);
			floodMap[i][j] = map[i][j];
			if (map[i][j] == '*') { flood.push(make_pair(i, j)); floodMap[i][j] = '0'; }
			else if (map[i][j] == 'S') { hedgehog.push(make_pair(i, j)); map[i][j] = '0'; }
			else if (map[i][j] == 'D') goal = make_pair(i, j);
		}

	while (!flood.empty())
	{
		pair<int, int> current = flood.front(); flood.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = current.first + nx[i], y = current.second + ny[i];
			if (inRange(x, y) && floodMap[x][y] == '.')
			{
				flood.push(make_pair(x, y));
				floodMap[x][y] = floodMap[current.first][current.second] + 1;
			}
		}
	}

	while (!hedgehog.empty())
	{
		pair<int, int> current = hedgehog.front(); hedgehog.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = current.first + nx[i], y = current.second + ny[i];
			if (map[x][y] == 'D')
			{
				map[x][y] = map[current.first][current.second] + 1;
				break;
			}
			if (inRange(x, y) && map[x][y] == '.' && map[current.first][current.second] < floodMap[x][y] - 1)
			{
				hedgehog.push(make_pair(x, y));
				map[x][y] = map[current.first][current.second] + 1;
			}
		}
	}

	if (map[goal.first][goal.second] == 'D') printf("KAKTUS\n");
	else printf("%c\n", map[goal.first][goal.second]);
	return 0;
}

//#include <iostream>
//#include <queue>
//using namespace std;
//
//char map[50][50];
//char check[50][50];
//
//int nx[] = { -1, 1, 0, 0 };
//int ny[] = { 0, 0, -1, 1 };
//
//int R, C;
//
//bool inRange(int x, int y)
//{
//	return x >= 0 && x < R && y >= 0 && y < C;
//}
//
//int main(void)
//{
//	scanf("%d %d", &R, &C);
//
//	queue<pair<int, int>> hedgehog1, hedgehog2, flood1, flood2;
//	pair<int, int> goal;
//	for (int i = 0; i < R; i++)
//		for (int j = 0; j < C; j++)
//		{
//			scanf(" %c", &map[i][j]);
//			if (map[i][j] == '*') { check[i][j] = true; flood1.push(make_pair(i, j)); }
//			else if (map[i][j] == 'S') { check[i][j] = true; hedgehog1.push(make_pair(i, j)); map[i][j] = '0'; }
//			else if (map[i][j] == 'D') goal = make_pair(i, j);
//		}
//
//	bool ending = false;
//	while (!hedgehog1.empty() || !flood1.empty())
//	{
//		pair<int, int> current;
//		while (!hedgehog1.empty())
//		{
//			current = hedgehog1.front(); hedgehog1.pop();
//
//			if (map[current.first][current.second] != '*')
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					int x = current.first + nx[i], y = current.second + ny[i];
//					if (inRange(x, y) && !check[x][y])
//					{
//						if (map[x][y] == '.')
//						{
//							check[x][y] = true; hedgehog2.push(make_pair(x, y));
//							map[x][y] = map[current.first][current.second] + 1;
//						}
//						else if (map[x][y] == 'D')
//						{
//							map[x][y] = map[current.first][current.second] + 1;
//							ending = true;
//							break;
//						}
//					}
//				}
//			}
//		}
//		if (ending) break;
//		hedgehog1 = hedgehog2;
//		queue<pair<int, int>> tempHedgehog;
//		hedgehog2 = tempHedgehog;
//
//		while (!flood1.empty())
//		{
//			current = flood1.front(); flood1.pop();
//			for (int i = 0; i < 4; i++)
//			{
//				int x = current.first + nx[i], y = current.second + ny[i];
//				if (inRange(x, y) && map[x][y] != '*' && map[x][y] != 'D' && map[x][y] != 'X')
//				{
//					check[x][y] = true; flood2.push(make_pair(x, y));
//					map[x][y] = '*';
//				}
//			}
//		}
//		flood1 = flood2;
//		queue<pair<int, int>> tempFlood;
//		flood2 = tempFlood;
//	}
//
//	if (map[goal.first][goal.second] == 'D') printf("KAKTUS\n");
//	else printf("%d\n", map[goal.first][goal.second] - '0');
//	return 0;
//}