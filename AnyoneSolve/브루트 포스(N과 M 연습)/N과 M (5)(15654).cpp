#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tempVector;
int intArray[9] = {0, };
bool checkArray[9] = {false,};
void GetNM(int tempN, int tempM, int count)
{
    if(count == tempM)
    {
        for(int i = 0; i < count; i++)
        {
            cout << intArray[i] << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = 0; i < tempN; i++)
    {
        if(checkArray[i])
            continue;
        checkArray[i] = true;
        intArray[count] = tempVector[i];
        GetNM(tempN, tempM, count + 1);
        checkArray[i] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN, tempM;

    cin >> tempN >> tempM;

    for(int i = 0; i < tempN; i++)
    {
        int temp;  
        cin >> temp;

        tempVector.push_back(temp);
    }
    
    sort(tempVector.begin(), tempVector.end());

    GetNM(tempN, tempM, 0);
}