#include <iostream>
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	int gcd, lcm = a * b;

	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	gcd = a;
	lcm /= gcd;

	cout << gcd << '\n';
	cout << lcm << '\n';

	return 0;
}