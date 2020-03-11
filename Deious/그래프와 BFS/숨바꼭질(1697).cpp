#include <iostream>
#include <queue>

int time[100001];
bool check[100001];
int MAX = 100000;

using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	queue<int> q;
	q.push(a);
	check[a] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next : {now - 1, now + 1, now * 2})
		{
			if (0 <= next && next <= MAX)
			{
				if (check[next] == false)
				{
					q.push(next);
					check[next] = true;
					time[next] = time[now] + 1;
				}
				if (check[next] == true && time[next] > time[now] + 1)
				{
					q.push(next);
					time[next] = time[now] + 1;
				}
			}
		}
	}
	printf("%d", time[b]);

	return 0;
}