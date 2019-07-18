#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int L, C;
	scanf("%d %d", &L, &C);
	
	vector<char> passwords(C);
	vector<bool> consonants(C);
	for (int i = 0; i < C; i++)
		scanf(" %c", &passwords[i]);
	sort(passwords.begin(), passwords.end());
	for (int i = 0; i < C; i++)
		if (passwords[i] == 'a' || passwords[i] == 'e' || passwords[i] == 'i' || passwords[i] == 'o' || passwords[i] == 'u') consonants[i] = true;

	vector<int> p(C);
	for (int i = 0; i < L; i++) p[i] = 1;
	for (int i = L; i < C; i++) p[i] = 0;

	do
	{
		int consonant = 0, vowel = 0;
		for (int i = 0; i < C; i++)
			if (p[i] == 1)
				if (consonants[i]) consonant++;
				else vowel++;

		if (consonant >= 1 && vowel >= 2)
		{
			for (int i = 0; i < C; i++)
				if (p[i] == 1) printf("%c", passwords[i]);
			printf("\n");
		}
	} while (prev_permutation(p.begin(), p.end()));

	return 0;
}