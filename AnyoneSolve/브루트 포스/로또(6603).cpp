#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN;

    while(true)
    {
        cin >> tempN;
        if(tempN == 0)
            break;
        
        vector<int> tempVectorA(tempN);
        vector<int> tempVectorB(tempN);

        for(int i = 0; i < tempN; i++)
        {
            cin >> tempVectorA[i];
        }

        for(int i = 0; i < 6; i++)
        {
            tempVectorB[i] = 1;
        }
        for(int i = 6; i < tempN; i++)
        {
            tempVectorB[i] = 0;
        }

        do
        {
            for(int i = 0; i < tempN; i++)
            {
                if(tempVectorB[i] == 1)
                    cout << tempVectorA[i] << " ";
            }
            cout <<"\n";
        } while (prev_permutation(tempVectorB.begin(), tempVectorB.end()));
        cout << "\n";
    }
}