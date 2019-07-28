#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	int N, M;
	int count = 0;
	cin >> N >> M;

	vector<int> tempV[1001];
	bool check[1001] = { false, };
	for (int i = 0; i < M; ++i)
	{
		int tempA, tempB;
		cin >> tempA >> tempB;

		tempV[tempA].push_back(tempB);
		tempV[tempB].push_back(tempA);
	}
	for (int i = 0; i < N; i++)
	{
		sort(tempV[i].begin(), tempV[i].end());
	}

	for (int i = 1; i <= N; ++i)
	{
		queue<int> tempQ;

		if (check[i])
			continue;

		tempQ.push(i);
		check[i] = true;

		while (!tempQ.empty())
		{
			int tempNum = tempQ.front();
			tempQ.pop();

			for (int j = 0; j < tempV[tempNum].size(); ++j)
			{
				int temp = tempV[tempNum][j];
				if (check[temp])
					continue;

				tempQ.push(temp);
				check[temp] = true;
			}
		}
		++count;
	}
	cout << count << '\n';
	return 0;
}