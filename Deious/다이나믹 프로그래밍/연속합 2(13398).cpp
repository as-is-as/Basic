#include <iostream>

using namespace std;

int check[100001][2];
int num[100001];

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a;
	cin >> a;
	
	for (int i = 1; i <= a; i++)
	{
		cin >> num[i];
	}

	check[1][0] = num[1];
	check[1][1] = num[1];
	int answer = num[1];

	for (int i = 2; i <= a; i++)
	{
		check[i][0] = Max(check[i - 1][0] + num[i], num[i]);
		check[i][1] = Max(check[i - 1][0], check[i - 1][1] + num[i]);
	}

	for (int i = 1; i <= a; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			answer = Max(answer, check[i][j]);
		}
	}

	cout << answer << '\n';

	return 0;
}