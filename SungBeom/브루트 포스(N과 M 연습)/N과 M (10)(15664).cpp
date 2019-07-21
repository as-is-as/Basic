#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
vector<int> sequence;
vector<bool> check;
set<string> ans;

void printSequence(vector<int>& nums, int index, int M)
{
	if (M == 0)
	{
		string s = "";
		for (int i = 0; i < nums.size(); i++)
			s += to_string(nums[i]) + " ";
		s += "\n";

		pair<set<string>::iterator, bool> pr = ans.insert(s);
		if (pr.second) cout << s;
		return;
	}

	for (int i = index; i < N; i++)
	{
		if (check[i]) continue;

		nums.push_back(sequence[i]);
		check[i] = true;
		printSequence(nums, i, M - 1);
		nums.pop_back();
		check[i] = false;
	}
}

int main(void)
{
	int M;
	scanf("%d %d", &N, &M);
	sequence.resize(N);
	check.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &sequence[i]);
		check[i] = false;
	}
	sort(sequence.begin(), sequence.end());

	vector<int> nums;
	printSequence(nums, 0, M);

	return 0;
}