#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int M;
	scanf("%d", &M);

	int nums[21];
	for (int i = 1; i <= 20; i++) nums[i] = 0;
	while (M--)
	{
		char command[7];
		int num;
		scanf("%s", command);
		if (!strcmp(command, "all"))
		{
			for (int i = 1; i <= 20; i++) nums[i] = 1;
			continue;
		}
		else if (!strcmp(command, "empty"))
		{
			for (int i = 1; i <= 20; i++) nums[i] = 0;
			continue;
		}

		scanf("%d", &num);
		if (!strcmp(command, "add"))
			nums[num] = 1;
		else if (!strcmp(command, "remove"))
			nums[num] = 0;
		else if (!strcmp(command, "check"))
			printf("%d\n", nums[num]);
		else if (!strcmp(command, "toggle"))
			nums[num] = (nums[num] + 1) % 2;
	}

	return 0;
}