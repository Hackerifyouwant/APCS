// #include <iostream>
// #include <map>
// #include <vector>

// #define ll long long
// #define endl '\n'

// using namespace std;
 
// map <char, vector<pair<char, int> > > mp;
// char start;
 
// int func(int start, int total){
//     if (!mp.count(start)) return total;
//     int maxi = 0;
//     for (pair<char, int> p: mp[start]){
//         maxi = max(func(p.first, total+p.second), maxi);
//     }
//     return maxi;
// }
 
// int main() {
//     int num;
//     while (cin >> start >> num){
//         mp.clear();
//         char a, b;
//         int n;
//         for (int i = 0; i < num; i++){
//             cin >> a >> b >> n;
//             mp[a].push_back({b, n});
//         }
//         cout << func(start, 0) << endl;
//     }
// }
#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

struct P{
    int node, weight;
}tmp;

vector<P> adj[105];
bool used[105];
int Max;

int transfer(char x){
    return int(x - 'A');
}

void dfs(int start, int weight){
    used[start] = 1;
    for(auto c : adj[start]){
        if(!used[c.node]){
            dfs(c.node, weight + c.weight);
        }
    }
    //cout << start << " " << weight << endl;
    Max = max(weight, Max);
    return;
}

int main(){
    int n;
    int start;
    char s;
    Max = -1e9;
    cin >> s;
    start = transfer(s);
    cin >> n;
    for(int i = 0; i < n; i++){
        char u, v;
        int w;
        cin >> u >> v >> w;
        tmp.node = transfer(v);
        tmp.weight = w;
        adj[transfer(u)].push_back(tmp);    
    }
    dfs(start, 0);
    cout << Max << endl;

    return 0;
}