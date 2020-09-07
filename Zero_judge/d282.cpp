#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int N, M;
map<int, string> name;

int main(){
    int Case = 0;
    while(cin >> N >> M){
        if(N == 0)break;
        int dp[25][25];
        name.clear();
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j)dp[i][j] = 0;
                else dp[i][j] = 1e9;
            }
        }
        for(int i = 1; i <= N; i++){
            string s;
            cin >> s;
            name[i] = s;
        }
        for(int i = 0; i < M; i++){
            int u, v, w;
            cin >> u >> v >> w;
            dp[u][v] = w;
            dp[v][u] = w;
        }
        int Min = 1e9;
        int Min_index;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                for(int k = 1; k <= N; k++){
                    if(dp[j][i] + dp[i][k] < dp[j][k]){
                        dp[j][k] = dp[j][i] + dp[i][k];
                    }
                }
            }
        }   
        for(int i = 1; i <= N; i++){
            int tmp = 0;
            for(int j = 1; j <= N; j++){
                tmp += dp[i][j];
            }
            if(Min > tmp){
                Min = tmp;
                Min_index = i; 
            }
        }
        cout << "Case #" << ++Case << " : " << name[Min_index].c_str() << endl;
    }

    return 0;
}