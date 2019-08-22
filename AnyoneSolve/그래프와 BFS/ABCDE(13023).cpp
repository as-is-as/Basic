#include <iostream>
#include <vector>

using namespace std;

vector<int> tempV[2001];
bool check[2001];
int N, M;
bool result;
void DFS(int temp, int cnt)
{
    if(cnt == 5)
    {
        result = true;
        return;
    }	
	
    check[temp] = true;
    for(int i = 0; i < tempV[temp].size(); ++i)
    {
		int num = tempV[temp][i];
		if(!check[num])
		{
			DFS(num, cnt + 1);
		}
    }
    check[temp] = false;
}
int main(void)
{
    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;

        tempV[tempA].push_back(tempB);
        tempV[tempB].push_back(tempA);
    }
    for(int i = 0; i < N; ++i)
    {
        DFS(i, 1);
        if(result)
            break;
    }
	
	int temp = result ? 1 : 0;
    cout << temp << '\n';
    return 0;
}