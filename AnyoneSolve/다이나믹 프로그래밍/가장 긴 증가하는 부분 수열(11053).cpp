#include <iostream>
#include <algorithm>

using namespace std;

int num[1001];
int numCount[1001];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=1; i<=n; ++i)
	{
		cin >> num[i];
	}

	for(int i=1; i<=n; ++i)
	{
		numCount[i] = 1;
		for(int j=i-1; j>=1; --j)
		{
			if(num[i] > num[j])
			{
				numCount[i] = max(numCount[i], numCount[j] + 1);
			}
		}
	}
	
	int maxCount = 0;
	for(int i=1; i<=n; ++i)
	{
		maxCount = max(maxCount, numCount[i]);
	}
	cout << maxCount << "\n";
	return 0;
}