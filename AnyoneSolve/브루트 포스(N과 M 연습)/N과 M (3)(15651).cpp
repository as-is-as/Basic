#include <iostream>

using namespace std;
void GetNM(int tempN, int tempM, int * checkArray, int checkCount)
{
    if(checkCount == tempM)
    {
        for(int i = 0; i < tempM; i++)
        {
            cout << checkArray[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= tempN; i++)
    {
        checkArray[checkCount] = i;
        GetNM(tempN, tempM, checkArray, checkCount + 1);
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tempN, tempM;
    int checkArray[8] = {0,};
    cin >> tempN >> tempM;
    GetNM(tempN, tempM, checkArray, 0);
    return 0;
}