#include <iostream>
using namespace std;

int main()
{
	int E, S, M;
	int e = 1, s = 1, m = 1;
	int count = 0;
	cin >> E;
	cin >> S;
	cin >> M;

	while (1) {
		count++;
		if ((e == E) && (s == S) && (m == M)) {
			cout << count;
			break;
		}
		else
		{
			e++;
			s++;
			m++;
			if (e == 16)
				e = 1;
			if (s == 29)
				s = 1;
			if (m == 20)
				m = 1;
		}
	}
	return 0;
}