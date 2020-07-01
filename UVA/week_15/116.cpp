#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

ll map[105][105];
ll m, n;

int way[3][2] = {{1, 1}, {-1, 1}, {0, 1}};

ll dp[105][105];
vector<ll> path;
        

int main(){
    while(cin >> m >> n && m != EOF){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
                dp[i][j] = 1e18;
            }
        }
        for(int i = 0; i < m; i++){
            dp[i][n - 1] = map[i][n - 1];
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 3; k++){
                    int nx = j - way[k][0];
                    int ny = i - way[k][1];
                    if(nx < 0)nx = m - 1;
                    if(nx >= m)nx = 0;
                    dp[nx][ny] = min(dp[nx][ny], dp[j][i] + map[nx][ny]);
                }
            }
        }
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        ll Min = 1e9;
        ll ans;
        ll min_index;
        for(int j = 0; j < m; j++){
            if(Min > dp[j][0]){
                Min = dp[j][0];       
            }
        }

        ans = Min;
        path.clear();
        for(int j = 0; j < m; j++){
            if(Min == dp[j][0]){
                path.push_back(j); 
                break;      
            }
        }
        
        for(int i = 0; i < n - 1; i++){
            int j = path.back();
            Min = 1e9;
            for(int k = 0; k < 3; k++){
                int nx = j + way[k][0];
                int ny = i + way[k][1];
                if(nx < 0)nx = m - 1;
                if(nx >= m)nx = 0;  
                if(Min > dp[nx][ny]){
                    Min = dp[nx][ny];
                    min_index = nx;
                }else if(Min == dp[nx][ny]){
                    Min = dp[nx][ny];
                    if(min_index > nx){
                        min_index = nx;
                    }
                }          
            }
            path.push_back(min_index);
        }
        
        
        for(int i = 0; i < path.size(); i++){
            if(i == path.size() - 1)cout << path[i] + 1;
            else cout << path[i] + 1 << " ";
        }
        cout << endl;
        cout << ans << endl;
        
    }
    return 0;
}

