#include <iostream>
#include <vector>
using namespace std;

vector<int> v1(12);
int num;

void pick(vector<int> v, int index)
{
	if (v.size() == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}
	int n = v.size();
	if (index == num)
		return;

	v.push_back(v1[index]);
	pick(v, index + 1);
	v.pop_back();
	pick(v, index + 1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	while (1)
	{
		cin >> num;
		
		if (num == 0)
			break;

		vector<int> v;

		for (int i = 0; i < num; i++)
		{
			int a;
			cin >> a;
			v1[i] = a;
		}
		pick(v, 0);
		cout << '\n';
	}
	return 0;
}