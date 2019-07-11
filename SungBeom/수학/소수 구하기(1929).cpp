#include <iostream>
using namespace std;

bool primeNums[1000001];

int main(void)
{
	int M, N;
	cin >> M >> N;

	for (int i = 2; i <= N; i++)
		primeNums[i] = true;
	for (int i = 2; i <= N; i++)
	{
		if (!primeNums[i]) continue;
		for (int j = 2; i*j <= N; j++)
			primeNums[i*j] = false;
	}

	for (int i = M; i <= N; i++)
		if (primeNums[i]) cout << i << '\n';
	return 0;
}