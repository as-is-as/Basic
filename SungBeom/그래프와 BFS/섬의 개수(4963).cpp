#include <iostream>
using namespace std;

int map[50][50];
bool check[50][50];

int nx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int ny[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int w, h;

bool inRange(int x, int y)
{
	return x >= 0 && x < h && y >= 0 && y < w;
}

int connect(int x, int y)
{
	if (check[x][y]) return 0;

	check[x][y] = true;
	if (map[x][y] == 0) return 0;

	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		int xx = x + nx[i], yy = y + ny[i];
		if (inRange(xx, yy) && map[xx][yy] == 1)
			sum += connect(x + nx[i], y + ny[i]);
	}

	return sum + 1;
}

int main(void)
{
	while (true)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &map[i][j]);
				check[i][j] = false;
			}

		int count = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				int num = connect(i, j);
				if (num) count++;
			}

		printf("%d\n", count);
	}

	return 0;
}