#include <iostream>

using namespace std;

long Check[201][201];

int main()
{
	int a, b, mul = 1000000000;

	cin >> a >> b;

	for (int i = 0; i <= a; i++)
	{
		Check[1][i] = 1;
	}

	for (int i = 2; i <= b; i++)
	{
		for (int j = 0; j <= a; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				Check[i][j] += Check[i - 1][k];
			}
			Check[i][j] %= mul;
		}
	}

	cout << Check[b][a] << endl;

	return 0;
}