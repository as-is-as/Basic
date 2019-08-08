#include <iostream>
#include <vector>
using namespace std;

int num;
int max = -1000000000, min = 1000000000;
vector<int> v(11);

void caculate(int index, int plus, int minus, int mul, int div, int sum)	// 계산 하는 식이 필요한 상황 어떻게 구현을 해야 하는가?
{
	if (index > num -1)
	{
		return;
	}

	if (plus < 0 || minus < 0 || mul < 0 || div < 0)
	{
		return;
	}

	if (sum > max) {
		max = sum;
	}

	if (sum < min)
	{
		min = sum;
	}

	caculate(index+1, plus - 1, minus, mul, div ,v[index] + v[index+1]);
	caculate(index+1, plus, minus - 1, mul, div, v[index] - v[index+1]);
	caculate(index+1, plus, minus, mul - 1, div, v[index] * v[index + 1]);
	caculate(index+1, plus, minus, mul, div - 1, v[index] / v[index + 1]);
}

int main()
{
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int a;
		cin >> a;
		v[i] = a;
	}

	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	caculate(0, plus, minus, mul, div, 0);
	cout << max << '\n' << min;
	return 0;
}