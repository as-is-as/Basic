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
	// 1. �Է� ���� ���� 2. �Է� ���� �ΰ��� �Ҽ��� ������ 3. �ΰ��� �Ҽ����� ���� �Է°��� ������ Ȯ��

	return 0;
}