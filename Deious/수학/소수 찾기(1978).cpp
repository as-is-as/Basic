#include <iostream>
#include <vector>
using namespace std;

bool primeCheck(int a) {
	if (a < 2) {
		return false;
	}

	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	int a;
	int count = 0;
	cin >> a;


	for (int i = 0; i < a; i++) {
		int b;
		cin >> b;
		if (primeCheck(b))
			count++;
	}
	cout << count;
	return 0;
}
