#include <iostream>

using namespace std;

int info[17][2];
int maxSum = 0;
int N;
void GetMaxPay(int startNum, int sum)
{
	if(startNum > N)
	{
		if(maxSum < sum)
			maxSum = sum;
		return;
	}
	GetMaxPay(startNum + 1, sum);

	if(startNum + info[startNum][0] -1 <= N)
		sum += info[startNum][1];
	GetMaxPay(startNum + info[startNum][0], sum);

	return;	
}
int main(void)
{
	scanf("%d", &N);

	for(int i = 1; i <= N; ++i)
	{
		scanf("%d %d", &info[i][0], &info[i][1]);
	}
	GetMaxPay(1, 0);

	printf("%d\n", maxSum);
	return 0;
}