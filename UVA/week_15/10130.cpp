#include<iostream>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

int N;
int p[1005], w[1005];
int G, MW[1005];
int dp[1005];


int main(){
    int Case;
    cin >> Case;
    while(Case--){ 
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> p[i] >> w[i];
        }
        cin >> G;
        for(int i = 0; i < G; i++){
            cin >> MW[i];
        }
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++){
            for (int j = 30; j >= w[i]; j--){
                dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        for(int i = 0; i < G; i++){
            ans += dp[MW[i]];
        }
        cout << ans << endl;
    }
    return 0;
} 