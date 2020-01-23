#include <cstdio>

int check[1001] = {0,};
int check1[1001] = {0,};
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
			if (num[i] > num[j] && check[i] < check[j] + 1)
			{
				check[i] = check[j] + 1;
			}
		}
	}

	for (int i = a; i >= 1; i--)
	{
		check1[i] = 1;
		for (int j = a; j >= i; j--)
		{
			if (num[i] > num[j] && check1[i] < check1[j] + 1)
			{
				check1[i] = check1[j] + 1;
			}
		}
	}

	for (int i = 1; i <= a; i++)
	{
		int temp = check[i] + check1[i] - 1;
		if (temp > answer)
		{
			answer = temp;
		}
	}
	printf("%d", answer);

	return 0;
}