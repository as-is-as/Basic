#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int CirculationResult(int tempA, int tempB, int op)
{
	switch (op)
	{
	case 0:
		return tempA + tempB;
	case 1:
		return tempA - tempB;
	case 2:
		return tempA * tempB;
	case 3:
		if (tempA < 0)
		{
			tempA *= -1;
			return -(tempA / tempB);
		}
		return tempA / tempB;
	}
	return 0;
}
int main(void)
{
	//ios_base::sync_with_stdio(false);
	int tempN;
	scanf("%d", &tempN);
	vector<int> vectorN(tempN);
	vector<int> vectorOpCount(4);
	vector<int> vectorOpPermutation;

	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < tempN; i++)
	{
		scanf("%d", &vectorN[i]);
	}
	for (int i = 0; i < 4; i++)
	{
        scanf("%d", &vectorOpCount[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < vectorOpCount[i]; j++)
		{
            vectorOpPermutation.push_back(i);
		}
	}


	do
	{
		int tempSum = vectorN[0];
		for (int i = 0; i < tempN - 1; i++)
		{
			tempSum = CirculationResult(tempSum, vectorN[i + 1], vectorOpPermutation[i]);
		}

		if (max < tempSum)
			max = tempSum;
		if (min > tempSum)
			min = tempSum;
	} while (next_permutation(vectorOpPermutation.begin(), vectorOpPermutation.end()));

    printf("%d\n%d\n",max, min);
	return 0;
}