#include <iostream>
using namespace std;

int ottSum(int num)
{
	if (num == 1) return 1;
	else if (num == 2) return 2;
	else if (num == 3) return 4;
	return ottSum(num - 1) + ottSum(num - 2) + ottSum(num - 3);
}

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", ottSum(n));
	}

	return 0;
}