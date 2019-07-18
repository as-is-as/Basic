#include <iostream>

using namespace std;
int GetFactorial(int temp)
{
    int num = 1;
    if(temp == 0)
        return 1;
    for(int i = temp; i > 1; i--)
    {
        num *= i;
    }
    return num;
}
int main(void)
{
    ios_base::sync_with_stdio(false);

    int tempT;
    int tempN;
    int totalSum;
    cin >> tempT;
    while(tempT--)
    {
        cin >> tempN;
        totalSum = 0;
        for(int i = 0; ; i++)
        {
            if(3 * i > tempN)
                break;
            for(int j = 0; ; j++)
            {
                if(3 * i + 2 * j > tempN)
                    break;
                for(int k = 0; ; k++)
                {
                    if(3 * i + 2 * j + 1 * k == tempN)
                    {
                        //printf("%d %d %d\n", i, j, k);
                        int a,b,c,d;

                        a = GetFactorial(i + j + k);
                        b = i == 0 ? 1 : GetFactorial(i);
                        c = j == 0 ? 1 : GetFactorial(j);
                        d = k == 0 ? 1 : GetFactorial(k);

                        totalSum+= (a / (b * c * d));
                    }
                    if(3 * i + 2 * j + 1 * k > tempN)
                    {
                        break;
                    }
                }
            }
        }
        cout << totalSum << endl;
    }
}