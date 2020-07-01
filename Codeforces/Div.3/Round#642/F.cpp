#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m, map[105][105], dp[105][105] , cost[105][105], ans = 1e18;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> map[i][j];
            }
        }
    
        for(int rx = 0; rx < n; rx++){
            for(int ry = 0; ry < m; ry++){
                //初始化
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        dp[i][j] = 1e18;
                    }
                }
                //初始化cost
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        cost[i][j] = 1e18;
                        ll goal = map[rx][ry] - rx - ry + i + j;
                        if(map[i][j] >= goal)cost[i][j] = map[i][j] - goal;
                        cout << goal << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                dp[0][0] = cost[0][0];
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(i < n - 1){
                            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost[i + 1][j]);
                        }if(j < m - 1){
                            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + cost[i][j + 1]);    
                        }
                    }
                }
                ans = min(ans, dp[n - 1][m - 1]);

            }
        }
        cout << ans << endl;
    }

    return 0;
}