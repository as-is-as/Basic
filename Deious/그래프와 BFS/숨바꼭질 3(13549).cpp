#include <iostream>
#include <queue>

using namespace std;

int check[100001];
int a, b;

int Bfs()
{
	queue<int> q;
	q.push(a);
	check[a] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == b)
		{
			return check[b];
		}

		if (now + 1 >= 0 && now + 1 <= 100000 && check[now + 1] > check[now] + 1)
		{
			check[now + 1] = check[now] + 1;
			q.push(now + 1);
		}

		if (now - 1 >= 0 && now - 1 <= 100000 && check[now - 1] > check[now] + 1)
		{
			check[now - 1] = check[now] + 1;
			q.push(now - 1);
		}

		if (now * 2 <= 100000 && check[now * 2] > check[now])
		{
			check[now * 2] = check[now];
			q.push(now * 2);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;

	for (int i = 0; i < 100001; i++)
	{
		check[i] = 1000000;
	}

	cout << Bfs() << "\n";

	return 0;
}