#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void GetHeight(int * tempArray, int sum,  int * tempA, int * tempB)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(sum - (tempArray[i] + tempArray[j]) == 100)
            {
                *tempA = i;
                *tempB = j;
                return;
            }    
        }
    }
    return;
}


int main(void)
{
    ios_base::sync_with_stdio(false);

    int tempArray[9] = {};
    int tempA = -1, tempB = -1;
    int sum = 0;
    vector<int> tempVector;
    
    // 난쟁이 키의 크기를 입력 받는다, 또한 이때 합계를 구한다.
    for(int i = 0; i < 9; i++)
    {
        cin >> tempArray[i];
        sum += tempArray[i];
    }
    // 난쟁이 키의 합을 구함.
    GetHeight(tempArray, sum, &tempA, &tempB);

    for(int i = 0; i < 9; i < i++)
    {
        if(i == tempA || i == tempB)
            continue;
        tempVector.push_back(tempArray[i]);
    }

    sort(tempVector.begin(), tempVector.end());


    for(vector<int>::iterator it = tempVector.begin(); it != tempVector.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}