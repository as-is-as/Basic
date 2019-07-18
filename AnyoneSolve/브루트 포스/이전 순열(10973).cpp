#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);

    int tempN;
    cin >> tempN;

    vector<int> tempVector(tempN);

    for(int i = 0; i < tempN; i++)
    {
        cin >> tempVector[i];
    }

    if(prev_permutation(tempVector.begin(), tempVector.end()))
    {
        for(vector<int>::iterator it = tempVector.begin(); it != tempVector.end(); ++it)
        {
            cout << *it << " ";
        }
    }
    else
    {
        cout << "-1";
    }
    cout << '\n';
    return 0;
}