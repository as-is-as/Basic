#include <iostream>
#include <algorithm>

using namespace std;

int num[1001];
int tempNum1[1001];
int tempNum2[1001];

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

    for(int i=1; i<=n; ++i)
    {
        tempNum1[i] = 1;
        for(int j=i-1; j>=1; --j)
        {
            if(num[i] > num[j])
                tempNum1[i] = max(tempNum1[i], tempNum1[j] + 1);
        }
    }
    for(int i=n; i>=1; --i)
    {
        tempNum2[i] = 1;
        for(int j=i+1; j<=n; ++j)
        {
            if(num[i] > num[j])
                tempNum2[i] = max(tempNum2[i], tempNum2[j] + 1);
        }
    }

    int maxCount = 0;
    for(int i=1; i<=n; ++i)
    {
        maxCount = max(maxCount, tempNum1[i] + tempNum2[i] - 1);
    }
    cout << maxCount;
    return 0;
}