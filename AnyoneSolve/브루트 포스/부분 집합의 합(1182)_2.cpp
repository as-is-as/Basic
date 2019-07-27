#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN, tempS;
    int tempCount = 0;

    cin >> tempN >> tempS;
    
    vector<int> tempVector(tempN);
    for(int i = 0; i < tempN; i++)
    {
        cin >> tempVector[i];
    }

    for(int i=1; i < (1 <<tempN); i++)
    {
        int sum = 0;
        for(int j=0; j<tempN; j++)
        {
            if(i & (1<<j))
            {
                sum += tempVector[j];
            }
        }

        if(tempS == sum)
        {
            tempCount+=1;
        }
    }
    cout << tempCount << '\n';
    return 0;
}