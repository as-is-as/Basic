#include <iostream>

using namespace std;

int check[10001];
int grape[10001];

int Max(int a, int b, int c)
{
	return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}

int main()
{
	int a;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		int b;
		cin >> b;
		grape[i] = b;
	}
	check[1] = grape[1];
	check[2] = grape[1] + grape[2];

	for (int i = 3; i <= a; i++)
	{
		check[i] = Max(check[i - 3] + grape[i - 1] + grape[i], check[i - 1], check[i - 2] + grape[i]);
	}
	cout << check[a];
	return 0;
}