#include <iostream>
using namespace std;

int main()
{
	bool num[1000000] = { false, };

	num[0] = true;
	num[1] = true;

	for (int i = 2; i <= 1000000; i++) {
		if (!num[i]) {
			for (int j = i * 2; j <= 1000000; j += i) {
				num[j] = true;
			}
		}
	}
	// 1. 입력 값을 받음 2. 입력 값을 두개의 소수로 분해함 3. 두개의 소수값의 합이 입력값과 같은지 확인

	return 0;
}