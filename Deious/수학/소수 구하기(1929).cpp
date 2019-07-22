#include <iostream>
using namespace std;

int main() {
	bool num[1000000] = {false,};
	int a,b;
	cin >> a;
	cin >> b;
	
	num[0] = true;
	num[1] = true;

	for (int i = 2; i <= 1000000; i++) {
		if (!num[i]) {
			for (int j = i*2; j <= 1000000; j += i) {
				num[j] = true;
			}
		}
	}
	
	for (int i = a; i <= b; i++) {
		if (!num[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}