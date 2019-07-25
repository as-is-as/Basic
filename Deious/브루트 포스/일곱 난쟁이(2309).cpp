#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int sum = 0;
	vector<int> vec;

	for (int i = 0; i < 9; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
		sum += a;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < 9; i++) {
		if (i == 8) {
			if ((sum - vec[i] - vec[8]) == 100) {
				vec.erase(vec.begin() + 9);
				vec.erase(vec.begin() + i);

				for (int k = 0; k < vec.size(); k++)
					cout << vec[k] << '\n';
				break;
				}
			}

		for (int j = i + 1; j < 9; j++) {
			if ((sum - vec[i] - vec[j]) == 100) {
				if (i > j) {
					vec.erase(vec.begin() + i);
					vec.erase(vec.begin() + j);
				}
				else {
					vec.erase(vec.begin() + j);
					vec.erase(vec.begin() + i);
				}
				
				for (int k = 0; k < vec.size(); k++)
					cout << vec[k] << '\n';
				return 0;
			}
		}
	}
	return 0;
}