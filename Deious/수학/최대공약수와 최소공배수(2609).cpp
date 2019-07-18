#include <iostream>
using namespace std;

int Max(int a, int b) {
	int max;
	while (b != 0) {
		max = a % b;
		a = b;
		b = max;
	}
	return a;
}

int main()
{
	int a, b, temp;

	cin >> a;
	cin >> b;
	temp = Max(a, b);
	cout << temp << endl;
	temp = temp * (a / temp) * (b / temp);
	cout << temp;	
}