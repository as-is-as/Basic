#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int tempArray[10];
int cnt[10];
int num[10];

vector<int> tempV;

void NumCount(int & N)
{
    int tempCount = 1;
    int tempIndex = 0;
    int tempNum = tempArray[0];


    for(int i = 1; i < N; ++i)
    {
        if(tempNum == tempArray[i])
        {
            ++tempCount;
        }
        else
        {
            cnt[tempIndex] = tempCount;
            num[tempIndex] = tempNum;

            tempCount = 1;
            ++tempIndex;
            tempNum = tempArray[i];
        }
    }
    cnt[tempIndex] = tempCount;
    num[tempIndex] = tempNum;
    N = tempIndex;
}
void GetResult(int N, int M, int startIndex , int index)
{
    if(M == index)
    {
        for(vector<int>::iterator it = tempV.begin(); it != tempV.end(); ++it)
        {
            cout << *it << ' ';
        }
        cout <<'\n';
    }

    for(int i = startIndex; i < N + 1; ++i)
    {
        if(cnt[i] != 0)
        {
            cnt[i] -= 1;
            tempV.push_back(num[i]);
            GetResult(N, M, i, index + 1);
            tempV.pop_back();
            cnt[i] +=1;
        }
    }
}
int main(void)
{
    cin.tie(0);
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> tempArray[i];
    }

    sort(tempArray, tempArray + N);
    NumCount(N);
    GetResult(N, M, 0, 0);

    return 0;
}