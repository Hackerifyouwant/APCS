#include<iostream>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    unsigned ll n, dp[7500];
    ll coin[5] = {1, 5, 10, 25, 50};
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for(int j = 0; j < 5; j++){
        for(int i = 1; i <= 7489; i++){
            if(i - coin[j] >= 0)dp[i] += dp[i - coin[j]];
        }
    }
    
    while(cin >> n){
        cout << dp[n] << endl;
    }

    return 0;
}