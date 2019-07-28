#include <iostream>

using namespace std;

void GetNM(int * tempArray, int tempN, int tempM, int checkCount, int checkIndex)
{
    if(checkCount == tempM)
    {
        for(int i = 0; i < tempM; i++)
        {
            cout << tempArray[i] << " ";
        }
        cout << "\n";

        return;
    }
    for(int i = checkIndex; i <= tempN; i++ )
    {
        tempArray[checkCount] = i;
        GetNM(tempArray, tempN, tempM, checkCount + 1, i + 1);
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tempN, tempM;
    int tempArray[9] = {0,};

    cin >> tempN >> tempM;
    GetNM(tempArray, tempN, tempM, 0, 1);

    return 0;
}