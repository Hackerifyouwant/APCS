// #include<iostream>
// #include<vector>
// #include<map>
// #include<set>
// #include<algorithm>

// #define ll long long
// #define endl '\n'

// using namespace std;

// int N, R;
// string place[105];
// map<string, int> string_to_node;
// map<int, string>node_to_string;
// vector<int> adj[105];
// set<int> ans;
// int vis[105];

// void dfs(int parent, int i){
//     vis[i] = up[i] = ++t;
// }

// int main(){
//     int cnt = 1;
//     while(cin >> N && N != 0){
//         for(int i = 0; i < N; i++){
//             cin >> place[i];
//             string_to_node[place[i]] = i;
//             node_to_string[i] = place[i];
//         }
//         cin >> R;
//         for(int i = 0; i < R; i++){
//             string roadA, roadB;
//             cin >> roadA >> roadB;
//             adj[string_to_node[roadA]].push_back(string_to_node[roadB]);
//             adj[string_to_node[roadB]].push_back(string_to_node[roadA]);
//         }
//         for(int i = 0; i < N; i++){
//             if(vis[i])dfs(i);
//         }
        
//         cout << "City map #" << cnt++ << ": " << ans.size() << " camera(s) found" << endl;
//         for(auto C : ans){
//             cout << node_to_string[C] << endl;
//         }
//         if(N != 0)cout << endl;



//         for(int i = 0; i < N; i++){
//             adj[i].clear();
//         }
//         string_to_node.clear();
//         node_to_string.clear();
//         ans.clear();
        

//     }

//     return 0;
// }
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#define MAX 101
#define ll long long
#define endl '\n'

using namespace std;

deque<int> F[MAX];
vector<string> name;
vector<string>::iterator itr;

bool cmp(const string &left, const string &right){
    string::const_iterator le, ri;
    for(le = left.begin(), ri = right.begin(); le != left.end() && ri != right.end(); le++, ri++){
        if((*le) != (*ri))return (*le) < (*ri);
    }
    if(left.size() != right.size())return left.size() < right.size();
}

int V[MAX], ar[MAX];
int up[MAX];//up[i]表示i點的子孫用back edge連到的最高祖先（走訪順序最小）
int t, mycount;

void DFS(int p, int i){
    V[i] = up[i] = ++t;
    int child = 0, target;
    bool ap = false;
    for(int a = 0; a < F[i].size(); a++){
        target = F[i][a];
        if(V[target])up[i] = min(up[i], V[target]);
        else{
            child++;
            DFS(i, target);
            up[i] = min(up[i], up[target]);
            if(up[target] >= V[i])ap = true;
        }
    }

    if(((i == p) && (child > 1)) || ((i != p) && (ap == true))){
        ar[i] = 1;
        mycount++;
    }
}

int getCityIndex(string p){
    int ct;
    itr = find(name.begin(), name.end(), p);
    if(itr < name.end())return itr - name.begin();
    else{
        name.push_back(p);
        return name.size() - 1;
    }
}

int main(){
    string x, y;
    int a, b, N ,R, ncase = 1;
    while(cin >> N && N != 0){
        t = 0;
        mycount = 0;
        name.clear();
        for(int j = 0; j < N; j++){
            cin >> x;
            a = getCityIndex(x);
        }
        for(int i = 0; i < N; i++){
            F[i].clear();
        }
        sort(name.begin(), name.end(), cmp);
        cin >> R;
        for(int i = 0; i < R; i++){
            cin >> x >> y;
            a = getCityIndex(x);
            b = getCityIndex(y);
            F[a].push_back(b);
            F[b].push_back(a);
        }
        memset(V, 0, sizeof(V));
        memset(ar, 0, sizeof(ar));
        memset(up, 0, sizeof(up));

        for(int i = 0; i < N; i++){
            if(V[i] == 0)DFS(i, i);
        }

        if(ncase > 1)cout << endl;
        cout << "City map #" << ncase++ << ": " << mycount << " camera(s) found" << endl;
        for(int i = 0; i < N; i++){          
            if (ar[i] > 0) cout << name[i] << endl;       
        }    

    }
    return 0;
}