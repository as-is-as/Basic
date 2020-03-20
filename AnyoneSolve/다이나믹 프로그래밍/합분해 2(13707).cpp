#include <iostream>
#define mod 1000000000
using namespace std;


long d[5001][5002];
int main(void)
{
    ios_base::sync_with_stdio(false);
    int N, K;

    cin >> N >> K;

    for(int i = 0; i <= N; ++i)
    {
        d[1][i] = 1;
    }

    for(int i = 2; i <= K; ++i)
    {
        for(int j = 0; j <= N; ++j)
        {
            d[i][j] = d[i - 1][j] + d[i][j -1]; 
            d[i][j] %= mod;
        }
    }
    cout << d[K][N] << endl;
    return 0;
}