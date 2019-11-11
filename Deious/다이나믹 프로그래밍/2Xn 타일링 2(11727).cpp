#include <iostream>

using namespace std;

int check[1001];

int main()
{
	check[0] = 1;
	check[1] = 1;

	int a;
	scanf("%d", &a);

	for (int i = 2; i <= a; i++)
	{
		check[i] = (check[i - 1] + check[i - 2] * 2) % 10007;
	}

	printf("%d\n", check[a]);
	return 0;
}