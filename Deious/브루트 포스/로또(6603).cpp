#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	while (1) 
	{
		int num;
		cin >> num;

		if (num == 0) break;

		vector<int> v;
		vector<int> check(num);
		for (int i = 0; i < num; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		
		for (int i = 0; i < 6; i++) {
			check[i] = 0;
		}
		for (int i = 6; i < num; i++)
			check[i] = 1;

		do
		{
			for (int i = 0; i < num; i++) {
				if (check[i] == 0) {
					cout << v[i] << " ";
				}
			}
			cout << '\n';
		}
		while (next_permutation(check.begin(),check.end()));
		cout << '\n';
	}
	return 0;
}