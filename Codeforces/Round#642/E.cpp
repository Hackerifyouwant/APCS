#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string s;
        cin >> n >> k >> s;
        int dp[n];
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i] = s[i] - '0';
            if(i >= k){
                dp[i] = max(dp[i], dp[i - k] - 1 + 2 * (s[i] - '0'));
            }
            ans = max(ans, dp[i]);    
            //cout << i << " " << dp[i] << endl;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += s[i] - '0';
        }
        cout << cnt - ans << endl;
    }

    return 0;
}