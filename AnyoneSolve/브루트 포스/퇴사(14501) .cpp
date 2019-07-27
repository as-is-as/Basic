#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN;
    int max = 0;
    cin >> tempN;

    vector<int> tempMoeny(tempN);
    vector<int> tempDay(tempN);

    for(int i = 0; i < tempN; i++)
    {
        cin >> tempDay[i] >> tempMoeny[i];
    }
    for(int i = 0; i < tempN; i++)
    {
       
        int tempMax = 0;
        int tempPos = 0;
        // 7 
        while(true)
        {
            if(i + tempDay[i] + tempPos>= tempN)
                break;  

            tempMax = tempMoeny[i];
            int pos = i + tempDay[i] + tempPos;
            tempPos++;

            while(true)
            {
                if(tempDay[pos] + pos > tempN)
                {   
                    break;
                }
                tempMax += tempMoeny[pos];
                pos += tempDay[pos];
                if(pos >= tempN)
                    break;
            }
            if(max < tempMax)
            {
                max = tempMax;
            }
        }
    }

    cout << max << '\n';
    return 0;
}