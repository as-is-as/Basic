#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool check(string &password)
{
	int ja = 0;
	int mo = 0;

	for (char x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			mo++;
		}
		else
		{
			ja++;
		}
	}
	return ja >= 2 && mo >= 1;
}

void go(int n, vector<char> &alpha, string password, int i)
{
	if (password.length() == n)
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}

	if (i >= alpha.size())
		return;

	go(n, alpha, password + alpha[i], i + 1);
	go(n, alpha, password , i + 1);
}

int main()
{
	int num, num1,temp = 0;
	cin >> num >> num1;
	vector<char> vc(num1);
	for (int i = 0; i < num1; i++) 
	{
		char c;
		cin >> c;
		vc[i] = c;
	}
	sort(vc.begin(), vc.end());
	go(num, vc, "", 0);
	return 0;
}