#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<int> nums(n);
		long long sum = 0;

		for (int i = 0; i < n; i++)
			cin >> nums[i];

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sum += GCD(nums[i], nums[j]);

		cout << sum << '\n';
	}

	return 0;
}