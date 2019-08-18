#include <iostream>
#include <climits>
#include <queue>
using namespace std;

int emoticon[1001][1001];

int main(void)
{
	int S;
	scanf("%d", &S);

	queue<pair<int, int>> q;
	q.push(make_pair(1, 0)); emoticon[1][0] = 1;
	while (!q.empty())
	{
		pair<int, int> current = q.front(); q.pop();
		
		if (!emoticon[current.first][current.first])
		{
			emoticon[current.first][current.first] = emoticon[current.first][current.second] + 1;
			q.push(make_pair(current.first, current.first));
		}
		if (current.first + current.second <= S && !emoticon[current.first + current.second][current.second])
		{
			emoticon[current.first + current.second][current.second] = emoticon[current.first][current.second] + 1;
			q.push(make_pair(current.first + current.second, current.second));
		}
		if (current.first > 0 && !emoticon[current.first - 1][current.second])
		{
			emoticon[current.first - 1][current.second] = emoticon[current.first][current.second] + 1;
			q.push(make_pair(current.first - 1, current.second));
		}
	}

	int min = INT_MAX;
	for (int i = 0; i <= S; i++)
		if (emoticon[S][i] && min > emoticon[S][i]) min = emoticon[S][i];
	printf("%d\n", min - 1);
	return 0;
}