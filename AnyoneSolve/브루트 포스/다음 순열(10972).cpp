#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tempN;
    cin >> tempN;

    vector<int> tempVector(tempN);

    for(int i = 1; i <= tempN; i++)
    {
        cin >> tempVector[i - 1];
    }


    if(next_permutation(tempVector.begin(), tempVector.end()))
        for(int i = 0 ; i < tempN; i++)
        {
            cout << tempVector[i] << " ";
        }
    else
    {
        cout << "-1";
    }
    cout <<"\n";
    
    
    return 0;
}