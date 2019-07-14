#include <iostream>

using namespace std;

bool primaryCheck(int temp)
{
    if(temp < 2)
        return false;

    for(int i = 2; i * i <= temp; i++)
    {
        if(temp % i == 0)
            return false;
    }
    return true;
}
int main(void)
{
    int temp;
    int tempA;
    int sum = 0;
    cin >> temp;

    while(temp--)
    {
        cin >> tempA;

        if(primaryCheck(tempA))
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}