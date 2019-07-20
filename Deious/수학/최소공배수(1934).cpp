#include <iostream>
using namespace std;

int Max(int a, int b) {
	int temp;
	if (a < b) {
		temp = b;
		b = a;
		a = temp;
	}

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int Min(int a, int b) {
	int temp = Max(a, b);
	return temp * (a / temp) * (b / temp);
}

int main()
{
	int a, b, temp, count;
	cin >> count;
	while (count != 0) {
		count--;
		cin >> a;
		cin >> b;
		temp = Min(a, b);
		cout << temp << '\n';
	}
	return 0;
}