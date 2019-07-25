#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int MaxArray(vector<int> &v) {
	int sum = 0;
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] - v[i + 1] < 0) {
			sum += (v[i] - v[i + 1]) * -1;
		}
		else {
			sum += v[i] - v[i + 1];
		}
	}
	return sum;
}

int main()
{
	int num,a;
	int max = 0;
	int temp = 0;
	vector<int> v;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	do 
	{
		temp = MaxArray(v);
		if (max < temp)
			max = temp;
	} while (next_permutation(v.begin(), v.end()));
	cout << max;
	return 0;
}