#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int s;
	cin >> s;
	vector<int> v(num);
	int count = 0;

	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		v[i] = a;
	}

	for (int i = 1; i < (1 << num); i++)
	{
		int sum = 0;
		for (int j = 0; j < num; j++)
		{
			if (i&(1 << j))
			{
				sum += v[j];
			}
		}
		if (sum == s)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}