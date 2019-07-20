#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);

    int tempN;
    cin >> tempN;

    int maxNum = 0;
    vector<int> tempVector(tempN);

    for(int i = 0; i < tempN; ++i)
    {
        cin >> tempVector[i];
    }
    sort(tempVector.begin(), tempVector.end());
    
    do    
    {
        int tempMax = 0;

        for(int i = 1; i < tempN; ++i)
        {
            int tempSum = tempVector[i - 1] - tempVector[i];
            
            if(tempSum < 0) 
            {  
                tempSum *= -1;
            }
            tempMax += tempSum;
            
        }
        if(maxNum < tempMax)
        {
            maxNum = tempMax;
        } 
    }while(next_permutation(tempVector.begin(), tempVector.end()));

    cout << maxNum << '\n';
    return 0;