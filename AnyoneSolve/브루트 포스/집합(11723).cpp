#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tempN;
	int tempList = 0;
	cin >> tempN;

	while (tempN--)
	{
		int tempX;
		
		string tempStr;
		cin >> tempStr;

		if (tempStr == "add")
		{
			cin >> tempX;
			tempList |= (1 << tempX);
		}
		else if(tempStr == "all")
		{
			tempList = (1 << 21) - 1;
		}
		else if(tempStr[0] == 'r')
		{
			cin >> tempX;
			if (tempList & (1 << tempX))
			{
				tempList &= ~(1 << tempX);
			}
		}
		else if(tempStr[0] == 'c')
		{
			cin >> tempX;
			if ((tempList & (1 << tempX)) == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
		}
		else if(tempStr[0] == 't')
		{
			cin >> tempX;
			tempList ^= (1 << tempX);
		}
		else if(tempStr[0] == 'e')
		{
			tempList = 0;
		}
		
	}
	return 0;
}