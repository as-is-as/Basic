#include <iostream>
#include <algorithm>

using namespace std;

int num[1001];
int tempSum[1001];

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
        tempSum[i] = num[i];

        for(int j=i-1; j>=1; --j)
        {
            if(num[i] > num[j])
            {
                tempSum[i] = max(tempSum[i], tempSum[j] + num[i]);
            }
        }
    }

    int maxSum = 0;
    for(int i=1; i<=n; ++i)
    {
        maxSum = max(maxSum, tempSum[i]);
    }
    cout << maxSum << '\n';

    return 0;
}