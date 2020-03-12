#include <iostream>

using namespace std;

long long num[91][2];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    num[1][1] = 1;
    
    for(int i=2; i<=n; ++i)
    {
        num[i][0] = num[i-1][1] + num[i-1][0];
        num[i][1] = num[i-1][0];
    }

    cout << num[n][0] + num[n][1] << "\n";
    return 0;
}