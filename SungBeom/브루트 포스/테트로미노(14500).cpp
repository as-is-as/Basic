#include <iostream>
using namespace std;

int shapes[19][3][2] =
{ {{0, 1}, {0, 2}, {0, 3}},
{{1, 0}, {2, 0}, {3, 0}},
{{0, 1}, {1, 0}, {1, 1}},
{{1, 0}, {2, 0}, {2, 1}},
{{1, 0}, {2, 0}, {2, -1}},
{{0, 1}, {0, 2}, {1, 0}},
{{1, 0}, {1, 1}, {1, 2}},
{{0, 1}, {1, 1}, {2, 1}},
{{0, 1}, {1, 0}, {2, 0}},
{{0, 1}, {0, 2}, {-1, 2}},
{{0, 1}, {0, 2}, {1, 2}},
{{1, 0}, {1, 1}, {2, 1}},
{{1, 0}, {1, -1}, {2, -1}},
{{0, 1}, {-1, 1}, {-1, 2}},
{{0, 1}, {1, 1}, {1, 2}},
{{0, 1}, {0, 2}, {1, 1}},
{{0, 1}, {0, 2}, {-1, 1}},
{{1, 0}, {2, 0}, {1, -1}},
{{1, 0}, {2, 0}, {1, 1}} };

int N, M;
int nums[500][500];

bool inRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int getSum(int x, int y)
{
	int max = 0;
	for (int i = 0; i < 19; i++)
	{
		int sum = nums[x][y];
		for (int j = 0; j < 3; j++)
		{
			if (!inRange(x + shapes[i][j][0], y + shapes[i][j][1]))
			{
				sum = 0;
				break;
			}
			sum += nums[x + shapes[i][j][0]][y + shapes[i][j][1]];
		}
		if (max < sum) max = sum;
	}
	return max;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf(" %d", &nums[i][j]);

	int sum, max = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			sum = getSum(i, j);
			if (max < sum) max = sum;
		}

	printf("%d\n", max);
	return 0;
}