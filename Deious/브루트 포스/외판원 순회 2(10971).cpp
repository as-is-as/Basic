#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	int min = 1000000;
	cin >> num;

	vector< vector<int> > v;
	vector<int> v1;
	for (int i = 0; i < num; i++) {
		v1.push_back(i);
	}

	for (int i = 0; i < num; i++) {
		vector<int> element;
		element.resize(num);
		v.push_back(element);
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int b;
			cin >> b;
			v[i][j] = b;
		}
	}

	do
	{
		bool check = true;
		int sum = 0;
		for (int i = 0; i < num - 1; i++)
		{
			if (v[v1[i]][v1[i + 1]] == 0) {
				check = false;
			}
			else
			{
				sum += v[v1[i]][v1[i + 1]];
			}
		}
		if (check && v[v1[num - 1]][v1[0]] != 0)
		{
			sum += v[v1[num - 1]][v1[0]];
			if (min > sum)
				min = sum;
		}
	} while (next_permutation(v1.begin() + 1, v1.end()));
	cout << min;
	return 0;
}