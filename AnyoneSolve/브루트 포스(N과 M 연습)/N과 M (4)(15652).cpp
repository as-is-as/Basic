#include <iostream>

using namespace std;

int intArray[9];
void GetNM(int tempN, int tempM, int index, int count)
{
    if(count == tempM)
    {
        for(int i = 0; i < count; i++)
        {
            cout << intArray[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = index + 1; i <= tempN; i++)
    {
        intArray[count] = i;
        GetNM(tempN, tempM, index, count + 1);
        index++;
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tempN, tempM;

    cin >> tempN >> tempM;
    GetNM(tempN, tempM, 0, 0);
}