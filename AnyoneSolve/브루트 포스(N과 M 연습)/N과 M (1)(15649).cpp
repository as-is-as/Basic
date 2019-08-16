#include <iostream>
using namespace std;


void GetNM(int * inputArray, bool * checkArray ,int index ,int tempN, int tempM)
{
    if(index == tempM)
    {  
        for(int i = 0; i < index; i++)
        {
            cout << inputArray[i] << " ";
        }
        cout << '\n';
        
        return;
    }
    for(int i = 1; i <= tempN; i++)
    {
        if(checkArray[i])
        {
            continue;
        }
        checkArray[i] = true;
        inputArray[index] = i;

        GetNM(inputArray, checkArray, index + 1, tempN, tempM);

        checkArray[i] = false;
    }
    return;
}
int main(void)
{
    ios_base::sync_with_stdio(false);

    bool checkArray[9] = {false,};
    int inputArray[9] = {0, };
    int tempN, tempM;

    cin >> tempN >> tempM;

    GetNM(inputArray ,checkArray, 0, tempN, tempM);

    return 0;
}