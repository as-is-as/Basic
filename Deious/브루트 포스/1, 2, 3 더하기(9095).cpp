#include <iostream>
using namespace std;

int main()
{
	int testNum,num;
	int ary[] = { 1,2,3 };
	cin >> testNum;
	while (testNum--) {
		int count = 0;
		cin >> num;
		for (int a = 0; a < 3; a++) {
			if (ary[a] == num) count++;
			for (int b = 0; b < 3; b++) {
				if (ary[a] + ary[b] == num) count++;
				for (int c = 0; c < 3; c++) {
					if (ary[a] + ary[b] + ary[c] == num) count++;
					for (int d = 0; d < 3; d++) {
						if (ary[a] + ary[b] + ary[c] + ary[d] == num) count++;
						for (int e = 0; e < 3; e++) {
							if (ary[a] + ary[b] + ary[c] + ary[d] + ary[e] == num) count++;
							for (int f = 0; f < 3; f++) {
								if (ary[a] + ary[b] + ary[c] + ary[d] + ary[e] + ary[f] == num) count++;
								for (int g = 0; g < 3; g++) {
									if (ary[a] + ary[b] + ary[c] + ary[d] + ary[e] + ary[f] + ary[g] == num) count++;
									for (int h = 0; h < 3; h++) {
										if (ary[a] + ary[b] + ary[c] + ary[d] + ary[e] + ary[f] + ary[g] + ary[h] == num) count++;
										for (int i = 0; i < 3; i++) {
											if (ary[a] + ary[b] + ary[c] + ary[d] + ary[e] + ary[f] + ary[g] + ary[h] + ary[i] == num) count++;
											for (int j = 0; j < 3; j++) {
												if (ary[a] + ary[b] + ary[c] + ary[d] + ary[e] + ary[f] + ary[g] + ary[h] + ary[i] + ary[j] == num) count++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}