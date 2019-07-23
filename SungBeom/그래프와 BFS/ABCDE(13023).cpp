#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	vector<vector<int>> relation(N);

	while (M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	bool success = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < relation[i].size(); j++)
		{
			if (relation[i][j] != i)
			{
				for (int k = 0; k < relation[relation[i][j]].size(); k++)
				{
					if (relation[relation[i][j]][k] != i && relation[relation[i][j]][k] != relation[i][j])
					{
						for (int l = 0; l < relation[relation[relation[i][j]][k]].size(); l++)
						{
							if (relation[relation[relation[i][j]][k]][l] != i &&
								relation[relation[relation[i][j]][k]][l] != relation[i][j] &&
								relation[relation[relation[i][j]][k]][l] != relation[relation[i][j]][k])
							{
								for (int m = 0; m < relation[relation[relation[relation[i][j]][k]][l]].size(); m++)
								{
									if (relation[relation[relation[relation[i][j]][k]][l]][m] != i &&
										relation[relation[relation[relation[i][j]][k]][l]][m] != relation[i][j] &&
										relation[relation[relation[relation[i][j]][k]][l]][m] != relation[relation[i][j]][k] &&
										relation[relation[relation[relation[i][j]][k]][l]][m] != relation[relation[relation[i][j]][k]][l])
									{
										success = true;
										break;
									}
								}
							}
							if (success) break;
						}
					}
					if (success) break;
				}
			}
			if (success) break;
		}
		if (success) break;
	}

	if (success) printf("1\n");
	else printf("0\n");
	return 0;
}