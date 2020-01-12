#include <cstdio>

int check[1001];
int num[1001];

int main()
{
	int a, answer = 0;
	scanf("%d", &a);

	for (int i = 1; i <= a; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= a; i++)
	{
		check[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (num[j] > num[i] && check[i] < check[j] + 1)
			{
				check[i] = check[j] + 1;
			}
		}
	}

	for (int i = 1; i <= 1000; i++)
	{
		if (check[i] > answer)
		{
			answer = check[i];
		}
	}
	printf("%d", answer);

	return 0;
}