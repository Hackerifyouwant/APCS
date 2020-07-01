#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

ll dp[105];    

int main(){
    ll n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 50; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    while(cin >> n && n != 0){
        cout << dp[n] << endl;
    }
    return 0;
}