#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

stringstream ss;
map<string, ll>name;
vector<int> adj[10005];    
ll step[10005];
bool used[10005];

void dfs(ll start, ll end){
    //cout << start << " " << end << " " << step[start] << endl;
    used[start] = 1;
    for(auto c : adj[start]){
        if(!used[c]){
            step[c] = step[start] + 1;
            dfs(c, end);
        }
    }
}

int main(){
    ll n;
    cin >> n;
    getchar();
    ll cnt = 0;
    memset(step, 0, sizeof(step));
    memset(used, 0, sizeof(used));
    for(ll i = 0; i < 10005; i++){
        adj[i].clear();
    }
    name.clear();
    for(ll i = 0; i < n; i++){
        string s;
        string tmp;
        getline(cin, s);
        ss.clear();
        ss << s;
        ss >> tmp;
        string parent;
        parent = tmp;
        if(name.find(tmp) == name.end()){
            name[tmp] = cnt++;
        }

        while(ss >> tmp){
            if(name.find(tmp) == name.end()){
                name[tmp] = cnt++;
            }
            adj[name[parent]].push_back(name[tmp]);
            adj[name[tmp]].push_back(name[parent]);
        }
    }
    // for(auto m : name){
    //     cout << m.second << " ";
    //     for(auto c : adj[m.second]){
    //         cout << c << " "; 
    //     }
    //     cout << endl;
    // }
    string start, end;
    cin >> start >> end;
    dfs(name[start], name[end]);
    cout << step[name[end]] << endl;


    return 0;
}