#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int K, V, E;
bool check[20002];
bool checkColor;
int color[20002];
int useColor = 1;
vector<int> tempV[20002];	// 정점, first 연결된 정점, second 색상

void CheckBipartiteGraph(int index, int setColor)
{
	if(check[index])
	{
		return;
	}
	else
	{
		check[index] = true;
		color[index] = 3 - setColor;

		for(int i = 0; i < tempV[index].size(); ++i)
		{
			int indexTemp = tempV[index][i];

			if(!check[indexTemp])
			{
				CheckBipartiteGraph(indexTemp, color[index]);
				useColor = color[index];
			}
			else
			{
				if(color[index] == color[indexTemp])
				{
					checkColor = true;
				}
			}
		}
	}
}
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> K;

	while(K--)
	{
		cin >> V >> E;
		memset(check, false, sizeof(check));
		memset(color, 0, sizeof(color));
		for(int i = 1; i <= V; ++i)
		{
			tempV[i].clear();
		}

		for(int i = 1; i <= E; ++i)
		{
			int tempA, tempB;
			cin >> tempA >> tempB;

			tempV[tempA].push_back(tempB);
			tempV[tempB].push_back(tempA);
		}
		// sort
		for(int i = 1; i <= V; ++i)
		{
			sort(tempV[i].begin(), tempV[i].end());
		}
		// bfs
		for(int i = 1; i <= V; ++i)
		{
			CheckBipartiteGraph(i, useColor);
		}
		if(checkColor)
		{
			checkColor = false;
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
		}
	}
}