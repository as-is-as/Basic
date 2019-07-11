#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		int A, B;
		cin >> A >> B;
		int lcm = A * B;

		if (A < B)
		{
			int temp = A;
			A = B;
			B = temp;
		}

		while (B != 0)
		{
			int temp = A % B;
			A = B;
			B = temp;
		}
		lcm /= A;
		cout << lcm << '\n';
	}

	return 0;
}