#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int num, a;
	cin >> num;
	vector<int> v;
	for (int i = 0; i < num; i++) {
		cin >> a;
		v.push_back(a);
	}

	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}