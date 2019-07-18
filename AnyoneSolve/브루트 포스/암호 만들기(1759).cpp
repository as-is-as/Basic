#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempL, tempC;
    cin >> tempL >> tempC;

    vector<int> tempVectorL(tempC);
    vector<char> tempVectorC(tempC);

    for(int i = 0; i < tempC; i++)
    {
        cin >> tempVectorC[i];
    }

    for(int i = 0; i < tempL; i++)
    {
        tempVectorL[i] = 1;
    }
    for(int i = tempL; i < tempC; i++)
    {
        tempVectorL[i] = 0;
    }


    sort(tempVectorC.begin(), tempVectorC.end());

    do
    {
        int vowel = 0;
        int consonant = 0;
        for(int i = 0; i < tempC; i++)
        {
            if(tempVectorL[i] == 1)
            {
                //cout << tempVectorC[tempVectorL[i]] << endl;
                if(tempVectorC[i] == 'a' || tempVectorC[i] == 'e' || 
                tempVectorC[i] == 'i' || tempVectorC[i] == 'o' || tempVectorC[i] == 'u')
                {
                    vowel++;
                }
                else
                {
                    consonant++;
                }
            }
        }
        if(vowel >= 1 && consonant >= 2)
        {
            for(int i = 0; i < tempC; i++)
            {
                if(tempVectorL[i] == 1)
                {
                    cout << tempVectorC[i];
                }
            }
            cout <<"\n";
        }
    }while(prev_permutation(tempVectorL.begin(), tempVectorL.end()));

    return 0;
}