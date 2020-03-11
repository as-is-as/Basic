#include <iostream>

using namespace std;

int d[10001] = {0,};
int card[10001] = {0,};
void GetMinValue(int temp)
{
    d[0] = 0;
    d[1] = card[1];
    for(int i = 2; i <= temp; ++i)
    {
        d[i] = card[i];

        for(int j = 1; j < i; ++j)
        {
            if(card[j] + d[i - j] < d[i])
            {
                d[i] = card[j] + d[i - j];
            }
        }
    }

    cout << d[temp] <<'\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    for(int i = 1; i <= N; ++i)
    {
        cin >> card[i];
    }
    GetMinValue(N);

    return 0;
}