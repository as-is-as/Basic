// 화면, 클립보드가 존재함.
// 복사, 붙여넣기, 삭제 기능이 존재함
// 복사 : 화면에 있는 이모티콘 전체를 클립 보드에 복사함. 
//        이때 클립보드 내부는 복사한것으로 초기화됨
// 붙여넣기 : 클립보드에 있는 전체 내용을 화면에 복사함.
//            기존에 있던 화면의 이모티콘은 그대로 이며, 붙여넣기 된것만큼 개수증가
// 삭제 : 화면에 있는 이모티콘 중 하나를 삭제함
// 구하려는것은 : S개수 만큼 이모티콘을 만들려는데 걸리는 시간
// 처음은 화면 1, 클립보드 0

#include <queue>
#include <algorithm>
#include <iostream>
#include <climits>
#include <tuple>
#include <cstring>
using namespace std;

int d[1001][1001];
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int S;
    queue<pair<int,int>> tempQ;

    cin >> S;
    memset(d, -1, sizeof(d));

    tempQ.push(make_pair(1,0));
    d[1][0] = 0;

    while(!tempQ.empty())
    {
        int view, clip;
        tie(view, clip) = tempQ.front();

        tempQ.pop();

        if(d[view][view] == -1)
        {
            d[view][view] = d[view][clip] + 1;
            tempQ.push(make_pair(view, view));
        }
        if(view + clip <= S && d[view + clip][clip] == -1)
        {
            d[view + clip][clip] = d[view][clip] + 1;
            tempQ.push(make_pair(view + clip, clip));
        }
        if(view -1 >= 0 && d[view -1][clip] == -1)
        {
            d[view -1][clip] = d[view][clip] + 1;
            tempQ.push(make_pair(view -1, clip));
        }
    }
    int result = INT_MAX;
    for(int i = 0; i <= S; ++i)
    {
        if(d[S][i] != - 1)
        {
            if(result > d[S][i])
                result = d[S][i];
        }
    }

    cout << result << '\n';
    return 0;
}