#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    
    bool tempList[1000001];
    int tempA, tempB;

    scanf("%d %d", &tempA, &tempB);
    tempList[0] = true;
    tempList[1] = true;

    //  false인 경우 소수
    for(int i = 2; i + i < 1000001; i++)
    {
        if(!tempList[i])
        {
            for(int j = i * 2; j < 1000001; j += i )
            {
                tempList[j] = true;
            }
        }
    }

    for(int i = tempA; i <= tempB; i++)
    {
        if(!tempList[i])
            printf("%d\n", i);
    }
}