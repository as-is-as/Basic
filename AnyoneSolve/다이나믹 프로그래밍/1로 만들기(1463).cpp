#include <iostream>
using namespace std;


int tempA[1000001];

void SetArray(int num)
{
    tempA[1] = 0;

    for(int i =2; i <= num; ++i)
    {

        tempA[i] = tempA[i- 1] + 1;

        if(i % 2 == 0)
        {
            if(tempA[i / 2] + 1 < tempA[i])
                tempA[i] = tempA[i / 2] + 1;
        }
        if(i % 3 == 0)
        {
            if(tempA[i / 3] + 1 < tempA[i])
            {
                tempA[i] = tempA[i / 3] + 1;
            }
        }
    }
    cout << tempA[num] << '\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN;
    cin >> tempN;

    SetArray(tempN);
}