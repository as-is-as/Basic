#include <iostream>

using namespace std;

int num[1001][10];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < 10; ++i)
		num[1][i] = 1;


	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = j; k < 10; ++k)
			{
				num[i][j] += num[i - 1][k];
				num[i][j] %= 10007;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum += num[n][i];
	}
	cout << sum % 10007 << "\n";
	return 0;
}