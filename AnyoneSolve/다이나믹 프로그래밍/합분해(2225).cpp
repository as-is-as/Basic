#include <iostream>
using namespace std;

int tempNum[201][201];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=0; i<=n; ++i)
    {
        tempNum[1][i] = 1;
    }
    for(int i=0; i<=k; ++i)
    {
        tempNum[i][0] = 1;
    }

    for(int i=2; i<=k; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            tempNum[i][j] = tempNum[i-1][j] + tempNum[i][j-1];
            tempNum[i][j] %= 1000000000;
        }
    }
    
    cout << tempNum[k][n] << "\n";
    return 0;
}