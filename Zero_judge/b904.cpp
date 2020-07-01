#include<iostream>
#include<algorithm>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

ll dp[3005][3005];
ll Q[3005];

int main(){
    ll N, M, K, Min = 1e9;
    cin >> N >> M >> K;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            dp[i][j] = 1e9;
        }
    }
    
    for(ll i = 0; i < M; i++){
        ll x, y, d;
        cin >> x >> y >> d;
        dp[x][y] = d;
        dp[y][x] = d;
    }
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            for(ll k = 1; k <= N; k++){
                if(i == j || j == k || i == k)continue;
                if(dp[i][k] + dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    for(ll i = 0; i < K; i++){
        cin >> Q[i];
    }
    for(ll i = 0; i < K; i++){
        for(ll j = i + 1; j < K; j++){
            Min = min(Min, dp[Q[i]][Q[j]]);
        }
    }
    if(Min == 1e9)cout << "zombie" << endl;
    else cout << Min << endl;
    

    return 0;
}
// 5 7 3
// 1 2 4
// 1 3 2
// 1 5 7
// 2 3 1
// 2 5 3
// 3 4 5
// 4 5 8
// 5 1 4

// 5 7 2
// 1 2 4
// 1 3 2
// 1 5 7
// 2 3 1
// 2 5 3
// 3 4 5
// 4 5 8
// 1 4