#include <iostream>
#include <cstring>

#define ll long long
#define endl '\n'

using namespace std;

int dp[55][55]; //最多50個切割的地方
int a[55]; //第1～N個切割的地方，由小到大排列好。
 
int solve(int x, int y){
    if (dp[x][y] != -1) return dp[x][y];
    if (x + 1 == y) return dp[x][y] = 0;
    int cost = 1e9;
    for (int i = x + 1; i < y; i++){
        //枚舉中間的切割點
        cost = min(cost, solve(x, i) + solve(i, y));
    }
    return dp[x][y] = cost + a[y] - a[x];
}
 
int main() {
    int L, N;
    while (cin >> L){
        if (L == 0) break;
        memset(a, 0, sizeof(a));
        memset(dp, -1, sizeof(dp));
        cin >> N;
        for (int i = 1; i <= N; i++){
            cin >> a[i];
        }
        a[N + 1] = L;
        // N += 2;
        // for(int i = 0; i < N; i++){
        //     for(int j = N - 1; j > i; j--){
        //         dp[i][j] = a[j] - a[i]; 
        //         for(int k = i + 1; k < j - 1; k++){
        //             if(dp[i][k] + dp[k][j] < dp[i][j]){
        //                 dp[i][j] = dp[i][k] + dp[k][j]
        //             }
        //         }
        //     }
        // }
        cout << "The minimum cutting is " << solve(0, N + 1) << "." << endl;
    }
    return 0;
}