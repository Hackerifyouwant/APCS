// #include<iostream>
// #include<vector>
// #include<string.h>
// #include<queue>
// #include<algorithm>

// #define ll long long
// #define endl '\n'

// using namespace std;

// vector<int> adj[100005];
// int parent[100005];
// int step[100005];
// bool used[100005];
// bool child[100005];

// int main(){
//     int n;
//     cin >> n;
//     memset(parent, -1, sizeof(parent));
//     for(int i = 1; i <= n; i++){
//         int k;
//         cin >> k;
//         if(k == 0)child[i] = 1;
//         for(int j = 0; j < k; j++){
//             int node;
//             cin >> node;
//             adj[node].push_back(i);
//             parent[node] = i;
//         }
//     }
//     int root;
//     queue<int> Q;

//     for(int i = 1; i <= n; i++){
//         if(parent[i] == -1){
//             root = i;
//         }
//         if(child[i] == 1){
//             step[i] = 0;
//             Q.push(i);
//         }
//     }
//     int sum = 0;
//     while(!Q.empty()){
//         int tmp = Q.front();
//         Q.pop();
//         used[tmp] = 1;
//         for(auto c : adj[tmp]){
//                 step[c] = max(step[tmp] + 1, step[c]);
//                 Q.push(c);
//             //cout << " ^^ " << tmp << " " << c << " " << step[c] << " " << sum << endl;
//         }
//         //cout << endl;
//     }
//     for(int i = 1; i <= n; i++){
//         sum += step[i];
//         //cout << step[i] << endl;
//     }
//     cout << root << endl;
//     cout << sum << endl;

//     return 0;
// }
#include<iostream>
#include<vector>
#include<numeric>

#define ll long long
#define endl '\n'
#define MAX 100005

using namespace std;

vector<ll> map[MAX];
ll par[MAX], mroot, maxk;
ll h, sum = 0;
vector<ll> dp;


ll dfs(int start){
    ll h = 0;
    if(dp[start - 1] != -1)
        return dp[start - 1];
    for(int i = 0; i < map[start].size(); i++){
        h = max (h, dfs(map[start][i]) + 1);
    }
    dp[start-1] = h;
    return h;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++){
        int x;
        cin >> x;
        for(int y=0; y<x; y++){
            int a;
            cin >> a;
            par[a] = i;
            map[i].push_back(a);
        }
    }
    dp = vector<ll>(n, -1);
    for(int i = 1; i <= n; i++){
        if(par[i] == 0){
            mroot = i;
            dfs(mroot);
            cout << mroot <<endl;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(dp[i] != -1){
            sum += dp[i];
        }
    }
    ll ans = accumulate(dp.cbegin(), dp.cend(), 0);
    cout << sum << endl;
    return 0;
}