#include <iostream>

using namespace std;

long long check[91][2];

int main()
{
	check[1][0] = 1;
	check[1][1] = 1;

	long long a;
	cin >> a;

	for (int i = 2; i <= a; i++)
	{
		check[i][0] = check[i - 1][0] + check[i - 1][1];
		check[i][1] = check[i - 1][0];
	}

	cout << check[a][1];

	return 0;
}