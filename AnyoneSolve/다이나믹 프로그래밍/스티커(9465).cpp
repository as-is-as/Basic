#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int pages[100001][2];
int tempPages[100001][3];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i=0; i<2; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                cin >> pages[j][i];
            }
        }

        tempPages[1][0] = 0;
        tempPages[1][1] = pages[1][0];
        tempPages[1][2] = pages[1][1];
        for(int i=2; i<=n; ++i)
        {
            tempPages[i][0] = max(max(tempPages[i-1][0], tempPages[i-1][1]), tempPages[i-1][2]);
            tempPages[i][1] = max(tempPages[i-1][0], tempPages[i-1][2]) + pages[i][0];
            tempPages[i][2] = max(tempPages[i-1][0], tempPages[i-1][1]) + pages[i][1];
        }

        int maxNum = max(max(tempPages[n][0], tempPages[n][1]),tempPages[n][2]);
        cout << maxNum << "\n";

        memset(tempPages, 0, sizeof(tempPages));
    }
    return 0;
}