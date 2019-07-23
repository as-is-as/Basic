#include <iostream>
#include <queue>
using namespace std;

int position[100001];

bool inRange(int p)
{
	return p >= 0 && p < 100001;
}

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	queue<int> q;
	position[N] = 1; q.push(N);
	while (!q.empty())
	{
		int current = q.front(); q.pop();
		if (current == K) break;

		if (inRange(current - 1) && position[current - 1] == 0) { position[current - 1] = position[current] + 1; q.push(current - 1); }
		if (inRange(current + 1) && position[current + 1] == 0) { position[current + 1] = position[current] + 1; q.push(current + 1); }
		if (inRange(current * 2) && position[current * 2] == 0) { position[current * 2] = position[current] + 1; q.push(current * 2); }
	}
	printf("%d\n", position[K] - 1);
	return 0;
}