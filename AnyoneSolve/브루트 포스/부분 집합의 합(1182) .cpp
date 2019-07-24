#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SetVector(vector<int> & checkVector, int count)
{
    checkVector.clear();
    cout << "============" << endl;
    for(int i = 0; i< count; i ++)
    {
        checkVector[i] = 1;
    }
    for(int i = count; i < checkVector.size(); i++)
    {
        checkVector[i] = 0;
    }
    
    for(int i = 0; i < checkVector.size(); ++i)
    {
        cout << checkVector[i] <<" ";
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN, tempS;
    int resultCount = 0;
    cin >> tempN >> tempS;

    vector<int> tempVector(tempN);
    vector<int> checkVector(tempN, 0);

    for(int i = 0; i < tempN; ++i)
    {
        cin >> tempVector[i];
    }

    for(int i = 0; i < tempN; i++)
    {
        for(int k = 0; k< tempN - i; k++)
        {
            checkVector[k] = 1;
        }
        for(int k = tempN - i; k < checkVector.size(); k++)
        {
            checkVector[k] = 0;
        }

        do
        {
            int tempSum = 0;
            for(int j = 0; j < tempN; j++)
            {
                if(checkVector[j] == 1)
                {
                    tempSum += tempVector[j];
                }
            }
            if(tempS == tempSum)
                ++resultCount;
        } while (prev_permutation(checkVector.begin(), checkVector.end()));

    }
    
    cout << resultCount << '\n';
    
    return 0;
}