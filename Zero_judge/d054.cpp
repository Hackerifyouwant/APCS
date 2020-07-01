#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

unsigned ll dp[40];

int main(){
    int t, n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    for(int i = 3; i <= 40; i++){
        dp[i] = dp[i - 1] + 4 * dp[i - 2] + 2 * dp[i - 3]; 
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}