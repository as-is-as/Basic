#include <iostream>

bool primeNums[1000001];

int main(void)
{
	for (int i = 2; i < 1000001; i++)
		primeNums[i] = true;
	for (int i = 2; i < 1000001; i++)
	{
		if (!primeNums[i]) continue;
		for (int j = 2; i*j < 1000001; j++)
			primeNums[i*j] = false;
	}

	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0) break;

		bool possible;
		for (int i = 3; i <= n / 2; i++)
			if (primeNums[i] && primeNums[n - i])
			{
				printf("%d = %d + %d\n", n, i, n - i);
				possible = true;
				break;
			}
		if (!possible)
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}