#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int num[100001];
int tempNum[100001][2];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int maxNum;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
    }
    if (n > 1)
    {
        tempNum[1][0] = num[1];
        tempNum[n][1] = num[n];

        for (int i = 2; i <= n; ++i)
        {
            tempNum[i][0] = max(tempNum[i - 1][0] + num[i], num[i]);
        }
        for (int i = n - 1; i >= 1; --i)
        {
            tempNum[i][1] = max(tempNum[i + 1][1] + num[i], num[i]);
        }

        maxNum = INT_MIN;
        for(int i=1; i<=n; ++i)
        {
            maxNum = max(maxNum, tempNum[i][0]);
        }
        for (int i = 2; i < n; ++i)
        {
            maxNum = max(maxNum, tempNum[i-1][0] + tempNum[i+1][1]);
        }
    }
    else 
        maxNum = num[1];
    cout << maxNum << "\n";
}