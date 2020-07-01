#include<iostream>
#include<algorithm>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n, v[10005], w[10005], dp[10005];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
    }
    memset(dp, 0, sizeof(dp));
    int Max = -1e9;
    for(int i = 0; i < n; i++){
        for(int j = 100; j >= 0; j--){
            if(j - v[i] >= 0){
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
                //cout << " && " << j << " " << dp[j - v[i]] + w[i] << endl;
            }
            //cout <<j << " " << dp[j] << endl;
            Max = max(dp[j], Max);
        }
    }
    cout << Max << endl;
    

    return 0;
}
