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
        tempVector[i] = i + 1;
    }
    do
    {
        for(int i = 0; i < tempN; i++)
        {
            cout << tempVector[i] << " ";
        }
        cout <<'\n';
    }while(next_permutation(tempVector.begin(), tempVector.end()));
    return 0;
}