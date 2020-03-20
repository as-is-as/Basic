#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int num[100001];
int tempNum[100001];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; ++i)
    {
        cin >> num[i];
    }

    tempNum[1] = num[1];
    for(int i=2; i<=n; ++i)
    {
        tempNum[i] = max(tempNum[i-1] + num[i], num[i]);
    }

    int maxNum = INT_MIN;
    for(int i=1; i<=n; ++i)
    {
        maxNum = max(maxNum, tempNum[i]);
    }
    cout << maxNum << "\n";
    return 0;
}