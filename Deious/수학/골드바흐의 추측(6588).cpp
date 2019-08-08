#include <iostream>
using namespace std;

int main()
{
	bool num[1000000] = { false, };

	num[0] = true;
	num[1] = true;

	for (int i = 2; i <= 1000000; i++) {
		if (!num[i]) {
			for (int j = i * 2; j <= 1000000; j += i) {
				num[j] = true;
			}
		}
	}

	while (1)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		bool ok = false;
		for (int i = 3; i <= n / 2; i++)
		{
			if (!(num[i] || num[n - i])) {
				printf("%d = %d + %d\n", n, i, n - i);
				ok = true;
				break;
			}
		}
		if (!ok)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}