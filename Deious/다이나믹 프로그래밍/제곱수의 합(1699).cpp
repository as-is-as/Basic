#include <iostream>

using namespace std;

int check[100001];

int main()
{
	int a;
	cin >> a;

	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			if (check[i] > check[i - j * j] + 1 || check[i] == 0)
			{
				check[i] = check[i - j * j] + 1;
			}
		}
	}
	cout << check[a] << endl;

	return 0;
}