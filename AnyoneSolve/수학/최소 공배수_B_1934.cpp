#include <iostream>

using namespace std;

int main(void)
{
    int tempT;
    int tempA, tempB;
    int tempNum;
    int resultNum;
    // check num range
    do
    {
        cin >> tempT;
    } while (tempT < 1 || tempT > 1000);

    while(tempT--)
    {
        do
        {
            cin >> tempA >> tempB;
        }while(tempA < 1 || tempA > 45000 || tempB < 1 || tempB > 45000);
        resultNum = tempA * tempB;
        // get gcd
        while(true)
        {
            tempNum = tempA % tempB;
            tempA = tempB;
            tempB = tempNum;
    
            if(tempB == 0)
                break;
        }
        // get lcm
        printf("%d\n", resultNum / tempA);
    }
    return 0;
}