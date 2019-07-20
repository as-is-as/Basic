#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN;
    int min = INT_MAX;
    int tempList[11][11];
    
    cin >> tempN;
    vector<int> tempVector(tempN);
    // 마을
    for(int i = 0; i < tempN; i++)
    {
        tempVector[i] = i + 1;
    }

    // 비용에 대한 초기화
    for(int i = 0; i < tempN; i++)
    {
        for(int j = 0; j < tempN; j++)
        {
            cin >> tempList[i][j];
        }
    }

    do
    {
        int tempMin = 0;
        bool checkZero = false;
        for(int i = 1; i < tempN; i++)
        {
            int temp = tempList[tempVector[i-1] - 1][tempVector[i] - 1];
            //cout << "=== > " << temp << endl;
            if(temp == 0)
            {
                checkZero = true;
                break;
            }
            tempMin += temp;
        }

        if(!checkZero && tempMin != tempMin + tempList[tempVector[tempN -1] -1][tempVector[0] -1])
        {   
            tempMin += tempList[tempVector[tempN -1] -1][tempVector[0] -1];

            min = tempMin < min ? tempMin : min;
        }

    }while(next_permutation(tempVector.begin(), tempVector.end()));

    cout << min << "\n";

    return 0;
}