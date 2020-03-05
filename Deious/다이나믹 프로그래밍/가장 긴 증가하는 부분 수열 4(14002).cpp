#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int check[1001];
int num[1001];
int save[1001];
vector<int> v;

void go(int index)
{
	if (index == -1)
	{
		return;
	}
	v.push_back(num[index]);
	go(save[index]);
}

int main()
{
	int a, answer = 0;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < a; i++)
	{
		save[i] = -1;
		check[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (num[j] < num[i] && check[i] < check[j] + 1)
			{
				check[i] = check[j] + 1;
				save[i] = j;
			}
		}
	}

	for (int i = 0; i < a; i++)
	{
		if (check[i] > answer)
		{
			answer = check[i];
		}
	}

	cout << answer << endl;

	for (int i = 0; i < a; i++)
	{
		if (check[i] == answer)
		{
			v.push_back(num[i]);
			go(save[i]);
			break;
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}