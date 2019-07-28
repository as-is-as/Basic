#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool check[1001] = { false, };
vector<int> tempVector[1001];

void DFS(int temp)
{
	check[temp] = true;
	cout << temp << ' ';
	for (int i = 0; i < tempVector[temp].size(); ++i)
	{
		int tempT = tempVector[temp][i];

		if (!check[tempT])
		{
			DFS(tempT);
		}
	}
}
void BFS(int temp)
{
	queue<int> tempQueue;
	memset(check, false, sizeof(check) / sizeof(check[0]));

	tempQueue.push(temp);
	check[temp] = true;
	while (!tempQueue.empty())
	{
		int tempNum = tempQueue.front();
		tempQueue.pop();
		cout << tempNum << ' ';
		for (int i = 0; i < tempVector[tempNum].size(); i++)
		{
			if (!check[tempVector[tempNum][i]])
			{
				check[tempVector[tempNum][i]] = true;
				tempQueue.push(tempVector[tempNum][i]);
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	int tempN, tempM, tempV;

	cin >> tempN >> tempM >> tempV;

	for (int i = 0; i < tempM; ++i)
	{
		int tempA, tempB;
		cin >> tempA >> tempB;

		tempVector[tempA].push_back(tempB);
		tempVector[tempB].push_back(tempA);
	}
	for (int i = 0; i < tempN; i++)
	{
		sort(tempVector[i].begin(), tempVector[i].end());
	}
	DFS(tempV);
	cout << '\n';
	BFS(tempV);
	cout << '\n';
	return 0;
}