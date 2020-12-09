#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<bool> check;
set<string> ans;

void caculate(vector<int>& nums, int index, int m)
{
	if (m == 0)
	{
		string s = "";
		for (int i = 0; i < nums.size(); i++)
		{
			s += to_string(nums[i]) + " ";
		}
		s += "\n";

		pair<set<string> ::iterator, bool> pr = ans.insert(s);
		if (pr.second) cout << s;
		return;
	}

	for (int i = index; i < n; i++)
	{
		if (check[i]) continue;

		nums.push_back(v[i]);
		check[i] = true;
		caculate(nums, i, m - 1);
		nums.pop_back();
		check[i] = false;
	}
}

int main()
{
	int m;
	cin >> n >> m;
	v.resize(n);
	check.resize(n, false);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		check[i] = false;
	}
	sort(v.begin(), v.end());

	vector<int> nums;
	caculate(nums, 0, m);

	return 0;
}