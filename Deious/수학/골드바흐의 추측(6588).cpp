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
		cin >> n;

		if (n == 0)
			break;

		bool ok = false;
		for (int i = 3; i <= n/2; i++) 
		{
			if (!(num[i] || num[n - i])) {
				cout << n << " = " << i << " + " << n-i << '\n';
				ok = true;
				break;
			}
		}
		if (!ok)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}
	return 0;
}