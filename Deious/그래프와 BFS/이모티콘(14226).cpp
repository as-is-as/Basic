#include<iostream>
#include<queue>

using namespace std;

bool visit[2000][2000];

int Bfs(int s)
{
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(1, 0), 0));
	visit[1][0] = true;

	while (!q.empty())
	{
		int cur = q.front().first.first;
		int board = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (cur == s)
		{
			return time;
		}

		if (cur > 0 && cur < 2000)
		{
			if (visit[cur][cur] == false)
			{
				visit[cur][cur] = true;
				q.push(make_pair(make_pair(cur, cur), time + 1));
			}

			if (visit[cur - 1][board] == false)
			{
				visit[cur - 1][board] = true;
				q.push(make_pair(make_pair(cur - 1, board), time + 1));
			}
		}

		if (board > 0 && cur + board < 2000)
		{
			if (visit[cur + board][board] == false)
			{
				visit[cur + board][board] = true;
				q.push(make_pair(make_pair(cur + board, board), time + 1));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s;
	cin >> s;

	cout << Bfs(s) << "\n";

	return 0;
}