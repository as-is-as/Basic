#include <iostream>
#include <vector>
using namespace std;

int result = 0;
int num,answer;
int countSum = 0;
vector<int> v(20);

void ans(int i, int sum)
{
	if (i == num)
	{
		if (sum == answer)
		{
			countSum++;
		}
		return;
	}
	ans(i + 1, sum + v[i]);
	ans(i + 1, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int num;
	cin >> num;
	cin >> answer;
	
	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		v[i] = a;
		result += a;
	}
	ans(0, 0);
	cout << countSum;
	return 0;
}