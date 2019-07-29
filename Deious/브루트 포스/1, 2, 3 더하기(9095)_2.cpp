#include <iostream>
using namespace std;

int answer = 0;

void sum(int count, int ans)
{
	if (count == ans) {
		answer++;
		return;
	}
	else if(count > ans)
	{
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		sum(count + i, ans);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int num;
	cin >> num;
	while(num--)
	{
		int a;
		cin >> a;
		sum(0, a);
		cout << answer << '\n';
		answer = 0;
	}
	return 0;
}