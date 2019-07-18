#include <iostream>
using namespace std;

int N;
int T[15], P[15];
const int MIN = -15000;

int price(int index)
{
	if (index >= N) return 0;

	int price1;
	if (index + T[index] <= N) price1 = price(index + T[index]) + P[index];
	else price1 = 0;
	int price2 = price(index + 1);

	if (price1 > price2) return price1;
	else return price2;
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &T[i], &P[i]);

	printf("%d\n", price(0));
	return 0;
}