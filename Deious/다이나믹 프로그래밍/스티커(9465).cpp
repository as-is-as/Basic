#include <iostream>

using namespace std;

int check[2][100001];
int save[2][100001];

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b, max = 0;

	cin >> a;

	for (int i = 1; i <= a; i++)
	{
		cin >> b;

		for (int i = 0; i < b; i++)
		{
			cin >> check[0][i];
		}

		for (int i = 0; i < b; i++)
		{
			cin >> check[1][i];
		}

		save[0][0] = check[0][0];
		save[1][0] = check[1][0];
		save[0][1] = check[0][1] + save[1][0];
		save[1][1] = check[1][1] + save[0][0];

		for (int i = 2; i < b; i++)
		{
			save[0][i] = check[0][i] + Max(save[1][i - 1], save[1][i - 2]);
			save[1][i] = check[1][i] + Max(save[0][i - 1], save[0][i - 2]);
		}

		cout << Max(save[0][b - 1], save[1][b - 1])<<'\n';
	}
	
	return 0;
}