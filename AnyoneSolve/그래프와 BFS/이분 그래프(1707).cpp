#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> tempV[20001];
bool check[20001];
int color[20001];
int colorN = 1;

int K, V, E;

void bfs()
{
	for (int i = 1; i <= V; ++i)
	{
		if (check[i])
			continue;
		queue<int> tempQ;
		tempQ.push(i);
		check[i] = true;
		color[i] = 3 - colorN;
		colorN = 3 - colorN;

		while (!tempQ.empty())
		{
			int tempNum = tempQ.front();
			tempQ.pop();

			for (int j = 0; j < tempV[tempNum].size(); ++j)
			{
				int temp = tempV[tempNum][j];
				if (check[temp])
				{
					if (color[temp] == color[tempNum])
					{
						cout << "NO\n";
						return;
					}
					continue;
				}
				check[temp] = true;
				tempQ.push(temp);
				color[temp] = 3 - colorN;
			}
			colorN = 3 - colorN;
		}
	}
	cout << "YES\n";
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> K;


	while (K--)
	{
		cin >> V >> E;

		for (int i = 1; i <= V; ++i)
		{
			tempV[i].clear();
		}
		memset(check, false, V + 1);
		memset(color, 0, V + 1);


		for (int i = 0; i < E; ++i)
		{
			int tempA, tempB;
			cin >> tempA >> tempB;

			tempV[tempA].push_back(tempB);
			tempV[tempB].push_back(tempA);
		}
		bfs();
	}
	return 0;
}