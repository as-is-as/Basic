#include <iostream>
#include <vector>
using namespace std;

int sum = 0;

void caculate(vector<int> v, vector<int> ca, vector<int> caIndex, int temp)
{
	// v�� Ȧ�� �ε����� ���� ca�� �ε����� 0~3������ ������� �˾ƾ���
	for (int i = 1; i < temp; i + 2)
	{
		
	}
}

int main()
{
	// 1. ������ ������ �Է� �ް� �� ������ŭ ���ڸ� �Է� ���� 2. �� 4���� ������ �� �ְ� �Է¹��� ���� -1 ��ŭ�� ���� �� �� ����
	// ���� 2���� ����� �ϳ��� ���ڵ��� �� ����ִ´� ���� ���Ϳ��� �����ڵ��� ���� �� �����ڵ��� ������ �����鼭 ��� �ϸ� ����������?
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