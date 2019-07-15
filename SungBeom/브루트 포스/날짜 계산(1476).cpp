#include <iostream>
using namespace std;

int main(void)
{
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int num = S;
	while ((num - E) % 15 != 0 || (num - M) % 19 != 0)
		num += 28;

	printf("%d\n", num);
	return 0;
}