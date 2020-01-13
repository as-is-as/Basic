#include <iostream>

using namespace std;

int check[100001];
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

	int answer = num[1];
	check[1] = num[1];

	for (int i = 2; i <= a; i++)
	{
		check[i] = Max(check[i - 1] + num[i], num[i]);
		answer = Max(check[i], answer);
	}

	cout << answer << '\n';

	return 0;
}