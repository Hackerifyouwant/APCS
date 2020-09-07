#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int C, N, coin[10], dp[1005];
    cin >> C >> N;
    fill(dp, dp + C, 1e9);
    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= C; i++){
        for(int j = 0; j < N; j++){
            dp[i] += (dp[])
        }
    }
    for(int i = 1; i <= C; i++){
        cout << i << " " << dp[i] << endl;
    }
    //cout << dp[C] << endl;

    return 0;
}
