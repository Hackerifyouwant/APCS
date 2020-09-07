#include<iostream>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    ll dp[1000005];
    memset(dp, 0, sizeof(dp));
    int coin[3] = {1, 2, 2};
    dp[0] = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= 1000001; j++){
            if(j - coin[i] >= 0)dp[j] += dp[j - coin[i]]; 
        }
    }
    while(cin >> n){
        cout << dp[n] << endl;
    }

    return 0;
}