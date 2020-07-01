#include <iostream>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

int t;
int v[5] = {1, 5, 10, 25, 50};
int dp[10000];

void DP(){
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i = 0; i < 5; i++){
        for(int j = v[i]; j <= 7490; j++){
            dp[j] += dp[j - v[i]];
            //cout << j << " " << dp[j] << endl;
        }
    }
        
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    DP();
    while(cin >> t)
        cout << dp[t] << endl;
}