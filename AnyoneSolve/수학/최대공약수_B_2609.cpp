#include <iostream>

using namespace std;

int main(void)
{
    int tempA, tempB;
    int tempNum;
    int result; 
    do
    {
        cin >> tempA >> tempB;
    }while(tempA < 1 || tempA > 10000 || tempB < 1 || tempB > 10000);
    
    result = tempA * tempB;
    // 최대 공약수
    while(true)
    {
        tempNum = tempA % tempB;
        tempA = tempB;
        tempB = tempNum;

        if(tempB == 0)
            break;
    }
    // 최소 공배수
    printf("%d\n", tempA);
    printf("%d\n", result / tempA );

    return 0;
}