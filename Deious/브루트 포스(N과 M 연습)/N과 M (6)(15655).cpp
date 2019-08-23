#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(10);
vector<bool> b(10);	// 기본값은 false

void caculate(int index, int N, int M, vector<int> &v1, int start)
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
	for (int i = start; i < N; i++)
	{
		if (b[i]) continue;
		b[i] = true;
		v[index] = v1[i];
		caculate(index + 1, N, M, v1, i+1);
		b[i] = false;
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

	caculate(0, N, M, v1,0);
	return 0;
}