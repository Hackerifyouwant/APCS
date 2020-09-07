#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int N, dp[105];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < 25; i++){
        dp[i] = 2;
        for(int j = 1; j <= i; j++){
            dp[i] += dp[i - j] * (dp[j] - 1);
        }
        cout << i << " " << dp[i] << endl;
        //dp[i] = dp[i - 1] * dp[1] + dp[i - 2] * dp[2] + dp[i - 3] * dp[3] + 1;
    }
    while(cin >> N){

    }
    return 0;
}