#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int map[1001][1001];
int d[1001][1001][2];
const int posX[] = {0, 0, -1, 1};
const int posY[] = {-1, 1, 0, 0};
int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    queue<tuple<int, int, int>> tempQ;
    tempQ.push(make_tuple(0,0,0));
    d[0][0][0] = 1;
    while(!tempQ.empty())
    {
        int tempX, tempY, tempD;
        tie(tempX, tempY, tempD) = tempQ.front();
        tempQ.pop();
        for(int i = 0; i < 4; ++i)
        {
            int x = tempX + posX[i];
            int y = tempY + posY[i];

            if(x < 0 || x >= N || y < 0 || y >= M)
                continue;

            if(map[x][y] == 0 && d[x][y][tempD] == 0)
            {
                d[x][y][tempD] = d[tempX][tempY][tempD] + 1;
                tempQ.push(make_tuple(x,y,tempD));
            }
            if(tempD == 0 && map[x][y] == 1 && d[x][y][tempD + 1] == 0)
            {
                d[x][y][tempD + 1] = d[tempX][tempY][tempD] + 1;
                tempQ.push(make_tuple(x, y, tempD + 1));
            }
        }
    }

    if(d[N -1][M - 1][0] != 0 && d[N -1][M -1][1] != 0)
    {
        cout << min(d[N -1][M - 1][0], d[N -1][M -1][1]);
    }
    else if(d[N -1][M - 1][0] != 0)
    {
        cout << d[N -1][M - 1][0];
    }
    else if(d[N -1][M - 1][1] != 0)
    {
        cout << d[N -1][M - 1][1];
    }
    else
    {
        cout << -1;
    }
    return 0;
}