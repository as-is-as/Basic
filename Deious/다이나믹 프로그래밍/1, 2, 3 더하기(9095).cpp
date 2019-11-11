#include <iostream>

using namespace std;

int main()
{
	int a;
	scanf("%d", &a);

	while (a--)
	{
		int check[12] = {0,};
		check[0] = 1;

		int b;
		scanf("%d", &b);

		for (int i = 1; i <= b; i++)
		{
			if (i - 1 >= 0)
			{
				check[i] += check[i - 1];
			}
			if (i - 2 >= 0)
			{
				check[i] += check[i - 2];
			}
			if (i - 3 >= 0)
			{
				check[i] += check[i - 3];
			}
		}
		printf("%d\n", check[b]);
	}
	return 0;
}