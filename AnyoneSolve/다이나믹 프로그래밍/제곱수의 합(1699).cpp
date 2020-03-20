#include <iostream>
#include <algorithm>

using namespace std;

int num[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        num[i] = i;
        for(int j=1; j*j<=i; ++j)
        {
            num[i] = min(num[i], num[i-j*j] + 1);
        }
    }
    cout << num[n] << "\n";
    return 0;
}