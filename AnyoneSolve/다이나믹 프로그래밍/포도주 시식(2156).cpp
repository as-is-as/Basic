#include <iostream>
#include <algorithm>

using namespace std;

int winecup[10001];
int tempCup[10001][3];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=1; i<=n; ++i) 
    {
        cin >> winecup[i];
    }

    tempCup[1][1] = winecup[1];

    for(int i=2; i<=n; ++i)
    {
        tempCup[i][0] = max(max(tempCup[i-1][0], tempCup[i-1][1]), tempCup[i-1][2]);
        tempCup[i][1] = tempCup[i-1][0] + winecup[i];
        tempCup[i][2] = tempCup[i-1][1] + winecup[i];
    }

    int maxSum = 0;
    for(int i=0; i<3; ++i)
    {
        maxSum = max(maxSum, tempCup[n][i]);
    }
    cout << maxSum << "\n";
    return 0;
}