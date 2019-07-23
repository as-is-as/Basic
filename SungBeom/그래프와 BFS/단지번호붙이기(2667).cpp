#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25];
bool check[25][25];

int nx[] = { -1, 0, 1, 0 };
int ny[] = { 0, -1, 0, 1 };

int N;

bool inRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int connect(int x, int y)
{
	if (check[x][y]) return 0;

	check[x][y] = true;
	if (map[x][y] == 0) return 0;

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + nx[i], yy = y + ny[i];
		if (inRange(xx, yy) && map[xx][yy] == 1)
			sum += connect(x + nx[i], y + ny[i]);
	}

	return sum + 1;
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	vector<int> answer;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int num = connect(i, j);
			if (num) answer.push_back(num);
		}
	sort(answer.begin(), answer.end());

	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++)
		printf("%d\n", answer[i]);
	return 0;
}