#include <iostream>
#include <vector>

using namespace std;

int num[1001];
int tempNum[1001][2];

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
        tempNum[i][0] = 1;
        tempNum[i][1] = -1;

        for(int j=i-1; j>=1; --j)
        {
            if(num[i] > num[j])
            {
                if(tempNum[i][0] < tempNum[j][0] + 1)
                {
                    tempNum[i][0] = tempNum[j][0] + 1;
                    tempNum[i][1] = j;
                }
            }
        }
    }

    int tempPos = 0;
    int maxValue = 0;
    for(int i=1; i<=n; ++i)
    {
        if(maxValue < tempNum[i][0])
        {   
            tempPos = i;
            maxValue = tempNum[i][0];
        }
    }

    vector<int> tempV;
    while(true)
    {
        tempV.push_back(num[tempPos]);
        if(tempNum[tempPos][1] == -1)
            break;
        tempPos = tempNum[tempPos][1];
    }
    cout << maxValue << "\n";
    for(int i=tempV.size()-1; i>=0; --i)
    {
        cout << tempV[i] << " ";
    }
    return 0;
}