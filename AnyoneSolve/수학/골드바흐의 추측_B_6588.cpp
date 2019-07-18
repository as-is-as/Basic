#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	bool tempList[1000001];
	vector<int> tempVector;

	for (int i = 2; i * 2 < 1000001; i++)
	{
		if (!tempList[i])
		{
			tempVector.push_back(i);
			for (int j = i * 2; j < 1000001; j += i)
			{
				tempList[j] = true;
			}
		}
	}


	while (true)
	{
		int tempNum;
		int tempA, tempB;
		vector<int>::iterator it;

		scanf("%d", &tempNum);

		if (tempNum == 0)
			break;
			
		it = tempVector.begin();
		while(true)
		{
			it++;
			tempA = *it;
			tempB = tempNum - tempA;

			if (!tempList[tempB])
			{
				printf("%d = %d + %d\n", tempNum, tempA, tempB);
				break;
			}

			if (tempNum < *it)
			{
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
		}
	}
	return 0;
}