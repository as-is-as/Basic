#include <iostream>
#include <queue>

using namespace std;

bool check[100001];
int movValue[100001];

void bfs(int N, int K)
{
	queue<int> tempQ;
	check[N] = true;
	movValue[N] = 0;
	tempQ.push(N);

	while (!tempQ.empty())
	{
		int mov = tempQ.front();
		tempQ.pop();

		if (mov == K)
			break;

		if (mov - 1 >= 0)
		{
			if (!check[mov - 1])
			{
				check[mov - 1] = true;
				movValue[mov - 1] = movValue[mov] + 1;
				tempQ.push(mov - 1);
			}
		}
		if (mov + 1 <=  100000)
		{
			if (!check[mov + 1])
			{
				check[mov + 1] = true;
				movValue[mov + 1] = movValue[mov] + 1;
				tempQ.push(mov + 1);
			}
		}
		if (mov * 2 <= 100000)
		{
			if (!check[mov * 2])
			{
				check[mov * 2] = true;
				movValue[mov * 2] = movValue[mov] + 1;
				tempQ.push(mov * 2);
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	int N, K;

	cin >> N >> K;

	bfs(N, K); 

	cout << movValue[K] << '\n';
}