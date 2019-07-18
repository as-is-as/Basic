#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int t;
    int n;
    vector<int> tempList;
    
    cin >> t;
    while(t--)
    {
        cin >> n;
        long sum = 0;

        for(int i =0; i< n; i++)
        {
            int temp;
            cin >> temp;
            tempList.push_back(temp);
        }

        
        int tempA, tempB;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                tempA = tempList.at(i);
                tempB = tempList.at(j);

                while(true)
                {
                    int temp = tempA % tempB;
                    tempA = tempB;
                    tempB = temp;

                    if(tempB == 0)
                        break;
                }
                sum += tempA;
            }
        }
        printf("%ld\n", sum);
        tempList.clear();
    }

    return 0;
}