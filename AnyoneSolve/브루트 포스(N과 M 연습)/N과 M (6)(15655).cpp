#include <iostream>
#include <algorithm>

using namespace std;

int tempNum[10];
bool checkNum[10];
int resultNum[10];
void GetResult(int N, int M, int startIndex, int index)
{
    if(M == index)
    {
        for(int i = 0; i < M; ++i)
        {
            cout << resultNum[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = startIndex; i < N; ++i)
    {
        if(!checkNum[i])
        {
            checkNum[i] = true;
            resultNum[index] = tempNum[i];
            GetResult(N, M,  i + 1, index + 1);
            checkNum[i] = false;
        }
    }
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >>tempNum[i];
    }
    
    sort(tempNum, tempNum + N);
    GetResult(N, M, 0, 0);


    return 0;
}