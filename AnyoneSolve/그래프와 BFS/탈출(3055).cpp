#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

char map[52][52];
int dB[51][51];
int dW[51][51];

const int posX[] = {0, 0, -1, 1};
const int posY[] = {-1, 1, 0, 0};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int R, C;
    
    queue<pair<int, int>> waterPos;
    pair<int, int> beaverPos;
    pair<int, int> desPos;
    cin >> R >> C;

    for(int i = 0; i < R; ++i)
    {
        cin >> map[i];
    }
    

    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            if(map[i][j] == '.' || map[i][j] == 'X')    continue;
            if(map[i][j] == '*')
                waterPos.push(make_pair(i,j));
            else if(map[i][j] == 'D')
                desPos = make_pair(i, j);
            else if(map[i][j] == 'S')
                beaverPos = make_pair(i, j);
        }
    }

    queue<tuple<int,int,int>> tempQ;

    while(!waterPos.empty())
    {
        int tempX, tempY;
        tie(tempX, tempY) = waterPos.front();
        waterPos.pop();
        
        tempQ.push(make_tuple(tempX, tempY, -1));
        dW[tempX][tempY] = -1;
    }
    tempQ.push(make_tuple(beaverPos.first, beaverPos.second, 1));

    dB[beaverPos.first][beaverPos.second] = 0;

    while(!tempQ.empty())
    {
        int tempX, tempY, type;
        tie(tempX, tempY, type) = tempQ.front();
        tempQ.pop();
        for(int i = 0; i < 4; ++i)
        {
            int x = tempX + posX[i];
            int y = tempY + posY[i];

            if( x < 0 || x >= R || y < 0 || y >= C)
                continue;         

            if(type == -1)
            {    
                if(dW[x][y] != -1 && map[x][y] == '.')
                {
                    dW[x][y] = -1;
                    tempQ.push(make_tuple(x,y,-1));
                }
            }
            else
            {   
                if(map[x][y] == '.' || map[x][y] == 'D')
                {
                    if(dW[x][y] != -1 && dB[x][y] == 0)
                    {
                        dB[x][y] = dB[tempX][tempY] + 1;
                        tempQ.push(make_tuple(x, y, 1));
                    }
                }
            }
        }
    }

    if(dB[desPos.first][desPos.second] != 0)
        cout << dB[desPos.first][desPos.second];
    else
        cout << "KAKTUS";
    cout <<'\n';
    return 0;
}