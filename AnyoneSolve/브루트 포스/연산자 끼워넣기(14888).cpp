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
	ios_base::sync_with_stdio(false);
	int tempN;
	cin >> tempN;

	vector<int> vectorN(tempN);
	vector<int> vectorOpCount(4);
	vector<int> vectorOpPermutation(tempN - 1);

	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < tempN; i++)
	{
		cin >> vectorN[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> vectorOpCount[i];
	}

	int tempPos = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < vectorOpCount[i]; j++)
		{
			vectorOpPermutation[tempPos] = i;
			tempPos++;
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

	cout << max << '\n' << min << '\n';
	return 0;
}