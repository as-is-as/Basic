#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<int> v;
	for (int i = 1; i <= num; i++) {
		v.push_back(i);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

	while (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}