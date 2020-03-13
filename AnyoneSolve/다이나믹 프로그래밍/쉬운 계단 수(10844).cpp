#include <iostream>

using namespace std;

int num[101][10];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=1; i<10; ++i)
        num[1][i] = 1;
    
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<10; ++j) {
            if(j > 0) num[i][j] += num[i-1][j-1]; 
            if(j < 9) num[i][j] += num[i-1][j+1];

            num[i][j] %= 1000000000;
        }
    }
    
    long long sum = 0;
    for(int i=0; i<10; ++i) {
        sum += num[n][i];
    }
    cout << sum % 1000000000 << "\n";
    return 0;
}