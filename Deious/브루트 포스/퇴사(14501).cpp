#include <iostream>
#include <vector>
using namespace std;

vector<int> t(15);
vector<int> p(15);
int benefit =0;
int num;

void getMoney(int i, int sum)
{
	if (i > num)
	{
		return;
	}

	if (i == num)
	{
		if (sum > benefit)
		{
			benefit = sum;
		}
		return;
	}
	getMoney(i + t[i], sum + p[i]);
	getMoney(i + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int a, b;
		cin >> a >> b;
		t[i] = a;
		p[i] = b;
	}
	getMoney(0, 0);
	cout << benefit;
	return 0;
}