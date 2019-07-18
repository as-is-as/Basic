#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	scanf("%d", &N);
	vector<vector<int>> roads(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &roads[i][j]);

	vector<int> cities(N);
	for (int i = 0; i < N; i++)
		cities[i] = i;

	int min = 10000000;
	do {
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			if (roads[cities[i]][cities[i + 1]] == 0)
			{
				sum = 10000000;
				break;
			}
			sum += roads[cities[i]][cities[i + 1]];
		}
		if (roads[cities[N - 1]][cities[0]] != 0)
			sum += roads[cities[N - 1]][cities[0]];
		else continue;
		if (min > sum) min = sum;
		
	} while (next_permutation(cities.begin(), cities.end()));

	printf("%d\n", min);
	return 0;
}