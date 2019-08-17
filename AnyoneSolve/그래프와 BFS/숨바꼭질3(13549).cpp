#include <iostream>
#include <queue>

using namespace std;
bool check[1000000];
int d[1000000];
int MAX = 1000000;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    queue<int> firstQueue;
    queue<int> secondQueue;

    firstQueue.push(N);
    d[N] = 0;
    check[N] = true;

    while(!firstQueue.empty())
    {
        int tempNum = firstQueue.front();
        firstQueue.pop();

        if(tempNum * 2 < MAX)
        {
            if(check[tempNum * 2] == false)
            {
                d[tempNum * 2] = d[tempNum];
                check[tempNum * 2] = true;
                firstQueue.push(tempNum * 2);
            }
        }
        if(tempNum + 1 < MAX)
        {
            if(check[tempNum + 1] == false)
            {
                d[tempNum + 1] = d[tempNum] + 1;
                check[tempNum + 1] = true;
                secondQueue.push(tempNum + 1);
            }
        }
        if(tempNum - 1 >= 0)
        {
            if(check[tempNum -1] == false)
            {
                d[tempNum - 1] = d[tempNum] + 1;
                check[tempNum -1] = true;
                secondQueue.push(tempNum - 1);
            }
        }
        if(firstQueue.empty())
        {
            firstQueue = secondQueue;
            secondQueue = queue<int>();
        }
    }
    cout << d[K] << '\n';
}