#include <iostream>

using namespace std;

int map[500][500];

int block[19][3][2] = 
{    
    {{0,1}, {0,2}, {0,3}},    
    {{1,0}, {2,0}, {3,0}},    
    {{1,0}, {1,1}, {1,2}},    
    {{0,1}, {1,0}, {2,0}},    
    {{0,1}, {0,2}, {1,2}},    
    {{1,0}, {2,0}, {2,-1}},    
    {{0,1}, {0,2}, {-1,2}},    
    {{1,0}, {2,0}, {2,1}},    
    {{0,1}, {0,2}, {1,0}},    
    {{0,1}, {1,1}, {2,1}},    
    {{0,1}, {1,0}, {1,1}},    
    {{0,1}, {-1,1}, {-1,2}},    
    {{1,0}, {1,1}, {2,1}},    
    {{0,1}, {1,1}, {1,2}},    
    {{1,0}, {1,-1}, {2,-1}},    
    {{0,1}, {0,2}, {-1,1}},    
    {{0,1}, {0,2}, {1,1}},    
    {{1,0}, {2,0}, {1,1}},    
    {{1,0}, {2,0}, {1,-1}}
};

int main(void)
{
    int N,M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
    int tempMax = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            for(int k = 0; k < 19; ++k)
            {
                int sum = map[i][j];
                bool check = true;

                for(int l = 0; l < 3; ++l)
                {
                    int x = i + block[k][l][0];
                    int y = j + block[k][l][1];

                    if(0 <= x && x < N && 0 <= y && y <M)
                    {
                        sum += map[x][y];
                    }
                    else{
                        check = false;
                        break;
                    }
                }

                if(check && tempMax < sum)
                    tempMax = sum;
            }
        }
    }

    printf("%d\n", tempMax);
}