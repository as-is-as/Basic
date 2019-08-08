#include <iostream>
#include <vector>
using namespace std;

int sum = 0;

void caculate(vector<int> v, vector<int> ca, vector<int> caIndex, int temp)
{
	// v의 홀수 인덱스에 들어가는 ca의 인덱스가 0~3사이중 어디인지 알아야함
	for (int i = 1; i < temp; i + 2)
	{
		
	}
}

int main()
{
	// 1. 숫자의 갯수를 입력 받고 그 갯수만큼 숫자를 입력 받음 2. 총 4개의 연산자 가 있고 입력받은 갯수 -1 만큼을 소지 할 수 있음
	// 벡터 2개를 만들고 하나에 숫자들을 다 집어넣는다 남은 벡터에는 연산자들이 들어간다 이 연산자들을 순열로 돌리면서 계산 하면 되지않을까?
	int num,temp;
	cin >> num;
	temp = num * 2 - 1;
	vector<int> v(temp);
	for (int i = 0; i < temp; i++)
	{
		if (i % 2 == 1)
			continue;
		int a;
		cin >> a;
		v[i] = a;
	}
	vector<int> ca(4);
	vector<int> caIndex(4);
	for (int i = 0; i < 4; i++)
	{
		int b;
		cin >> b;
		ca[i] = b;
		if (b > 0) {
			caIndex[i] = i;
		}
		else
		{
			caIndex[i] = 0;
		}
	}
}