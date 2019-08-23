#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(10);

void caculate(int index, int N, int M, vector<int> &v1)
{
	if (index == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		v[index] = v1[i];
		caculate(index + 1, N, M, v1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> v1(N);

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v1[i] = a;
	}
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());		// 2개가 있는것들은 남겨놔야되는데 다 한개씩 남겨버림
	N = v1.size();

	caculate(0, N, M, v1);
	return 0;
}