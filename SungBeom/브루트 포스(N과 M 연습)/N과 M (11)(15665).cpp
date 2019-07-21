#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
vector<int> sequence;
set<string> ans;

void printSequence(vector<int>& nums, int M)
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

	for (int i = 0; i < N; i++)
	{
		nums.push_back(sequence[i]);
		printSequence(nums, M - 1);
		nums.pop_back();
	}
}

int main(void)
{
	int M;
	scanf("%d %d", &N, &M);
	sequence.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &sequence[i]);
	sort(sequence.begin(), sequence.end());

	vector<int> nums;
	printSequence(nums, M);

	return 0;
}