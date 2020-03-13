#include <iostream>

using namespace std;

int num[100001][4];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    num[1][1] = 1;
    num[2][2] = 1;
    num[3][1] = 1;
    num[3][2] = 1;
    num[3][3] = 1;

    for (int i = 4; i <= 100000; ++i)
    {
        num[i][1] = (num[i - 1][2] + num[i - 1][3]) % 1000000009;
        num[i][2] = (num[i - 2][1] + num[i - 2][3]) % 1000000009;
        num[i][3] = (num[i - 3][1] + num[i - 3][2]) % 1000000009;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 1; i < 4; ++i)
        {
            sum += num[n][i];
        }
        cout << sum % 1000000009 << "\n";
    }
    return 0;
}