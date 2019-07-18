#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int dwarves[9];
	for (int i = 0; i < 9; i++)
		scanf("%d", &dwarves[i]);

	vector<int> answer(7);
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			for (int k = j + 1; k < 5; k++)
				for (int l = k + 1; l < 6; l++)
					for (int m = l + 1; m < 7; m++)
						for (int n = m + 1; n < 8; n++)
							for (int o = n + 1; o < 9; o++)
								if (dwarves[i] + dwarves[j] + dwarves[k] + dwarves[l] + dwarves[m] + dwarves[n] + dwarves[o] == 100)
								{
									answer[0] = dwarves[i];
									answer[1] = dwarves[j];
									answer[2] = dwarves[k];
									answer[3] = dwarves[l];
									answer[4] = dwarves[m];
									answer[5] = dwarves[n];
									answer[6] = dwarves[o];
									break;
								}

	sort(answer.begin(), answer.end());
	for (int i = 0; i < 7; i++)
		printf("%d\n", answer[i]);
	return 0;
}