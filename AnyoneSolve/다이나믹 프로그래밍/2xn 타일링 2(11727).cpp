#include <iostream>

using namespace std;

int blockArray[1001];
// 재귀의 경우
int GetBlock(int temp)
{
    if(temp == 0 || temp == 1)
        return 1;
    blockArray[temp] = (GetBlock(temp -1) + 2 * GetBlock(temp - 2)) % 10007;
    
    return blockArray[temp];
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN;
    cin >> tempN;
    blockArray[0] = 1;
    blockArray[1] = 1;

    for(int i = 2; i <= tempN; i++)
    {
        blockArray[i] = (blockArray[i -1] +  2 * blockArray[i -2]) % 10007;
    }
    cout << blockArray[tempN] << endl;

    return 0;
}