#include <iostream>
using namespace std;

int tempArray[101];
int GetSumList(int temp, int totalCount)
{
    if(temp == 0)
        return ++totalCount;
    if(temp < 0)
        return 0;
    if(tempArray[temp] > 0)
        return tempArray[temp];
    tempArray[temp] = GetSumList(temp-1, totalCount) + GetSumList(temp-2, totalCount) + GetSumList(temp-3, totalCount);
    
    return tempArray[temp];
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN;
    cin >> tempN;
    while(tempN--)
    {
        int tempNum;
        cin >> tempNum;
        cout << GetSumList(tempNum, 0) << '\n';
    }
    return 0;
}