#include <iostream>
using namespace std;

bool primeNums[1001];

int main(void)
{
	for (int i = 2; i < 1001; i++)
		primeNums[i] = true;
	for (int i = 2; i < 1001; i++)
	{
		if (!primeNums[i]) continue;
		for (int j = 2; i*j < 1001; j++)
			primeNums[i*j] = false;
	}

	int N;
	cin >> N;

	int count = 0;
	while (N--)
	{
		int num;
		cin >> num;

		if (primeNums[num]) count++;
	}

	cout << count << '\n';
	return 0;
}