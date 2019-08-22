#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


set<int> tempSet;
int resultTemp[10];

void GetResult(int M, set<int>::iterator startIt, int index)
{
    if(M == index)
    {
        for(int i = 0; i < M; i++)
        {
            cout << resultTemp[i] << ' ';
        }
        cout <<'\n';
        return;
    }

    for(set<int>::iterator it = startIt; it != tempSet.end(); ++it)
    {
        resultTemp[index] = *it;
        
        GetResult(M, it,  index + 1);
    }
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        tempSet.insert(temp);
    }
    GetResult(M, tempSet.begin(), 0);
}