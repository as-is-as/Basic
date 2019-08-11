#include <iostream>
#include <vector>
using namespace std;

vector<int> v(10);
vector<bool> b(10);	// 기본값은 false

void caculate(int index, int N, int M)
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
	for (int i = 1; i <= N; i++)
	{
		if (b[i]) continue;
		b[i] = true;
		v[index] = i;
		caculate(index + 1, N, M);
		b[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;

	caculate(0, N, M);
	return 0;
}