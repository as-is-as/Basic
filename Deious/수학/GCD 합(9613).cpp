#include <iostream>
#include <vector>
using namespace std;

int main() {

	int count, a, b, temp;
	long sum = 0;
	vector<int> vec;
	cin >> count;

	while (count != 0) {
		count--;
		cin >> a;
		vec.clear();
		for (int i = 0; i < a; i++) {
			cin >> b;
			vec.push_back(b);
		}
		int vcount = vec.size();
		while (vcount != 0) {
			vcount--;

			for (int i = vcount-1; i >= 0; i--) {
				a = vec[vcount];
				b = vec[i];
				while (b!=0) {
					temp = a % b;
					a = b;
					b = temp;
				}
				sum += a;
			}
		}
		cout << sum << '\n';
		sum = 0;
	}
	return 0;
}