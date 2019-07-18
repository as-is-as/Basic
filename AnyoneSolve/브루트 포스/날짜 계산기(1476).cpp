#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);

    // 3개의 수를 이용해서 연도를 나타냄
    // 지구를 나타내는 수 E  1 <= E <= 15
    // 태양을 나타내는 수 S  1 <= S <= 28
    // 달을 나타내는 수 M    1 <= M <= 19

    // 1년은 1 1 1
    // 1년이 지날 때마다 세수 모두 1씩 증가함
    // 범위를 넘어서는 경우 1이 됨

    int tempE, tempS, tempM;
    int tempY = 1;
    cin >> tempE >> tempS >> tempM;

    while(true)
    {
        if(tempE == 1 && tempS == 1 && tempM == 1)
            break;
            
        tempE = tempE - 1 == 0 ? 15 : tempE - 1;
        tempS = tempS - 1 == 0 ? 28 : tempS - 1;
        tempM = tempM - 1 == 0 ? 19 : tempM - 1;

        ++tempY;
    }

    cout << tempY << endl;
}