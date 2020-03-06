#include <iostream>
using namespace std;

long tempArray[1000001];
long GetSumList(int temp)
{
    tempArray[0] = 1;
    tempArray[1] = 1;
    tempArray[2] = 2;

    for(int i = 3; i <= temp; i++)
    {
        tempArray[i] = tempArray[i-3] % 1000000009 + tempArray[i - 2] % 1000000009 + tempArray[i - 1] % 1000000009;
    }

    return tempArray[temp] % 1000000009;
}


int main(void)
{
    int tempN;
    long num;

    cin >> tempN;
    while(tempN--)
    {
        int tempNum;
        cin >> tempNum;
        cout << GetSumList(tempNum) << '\n';
    }
    return 0;
}