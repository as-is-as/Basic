#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

char map[101][101];
bool check[101][101];
int d[101][101];

int posX[] = { 0, 0, -1, 1};
int posY[] = { -1, 1, 0, 0};

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    
    for(int i = 0; i < M; ++i)
    {
        cin >> map[i];
    }
    memset(d, 10000, sizeof(d));
    queue<pair<int,int>> fQueue;

    fQueue.push(make_pair(0,0));
    d[0][0] = 0;
    check[0][0] = true;
    
    while(!fQueue.empty())
    {
        int tempX, tempY;
        tie(tempX, tempY) = fQueue.front();
        fQueue.pop();

        for(int i = 0; i < 4; ++i)
        {
            int x = tempX + posX[i];
            int y = tempY + posY[i];

            if( x >= 0 && x < M && y >= 0 && y < N)
            {
                if(map[x][y] == '0' && d[x][y] > d[tempX][tempY])
                {
                    d[x][y] = d[tempX][tempY];
                    fQueue.push(make_pair(x,y));
                }
                if(map[x][y] == '1' && d[x][y] > d[tempX][tempY] + 1)
                {
                    d[x][y] = d[tempX][tempY] + 1;
                    fQueue.push(make_pair(x, y));
                }
            }
        }
    }
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << d[M - 1][N -1] << '\n';
    return 0;
}