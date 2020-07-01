#include<iostream>
#include<vector>
#include<set>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;


bool vis[105];
set<char> adj[105];
set<char> node;
int cnt;

void dfs(char c){
    if(vis[c] == true){
        return;
    }
    vis[c] = true;
    for(auto C : adj[c]){
        dfs(C);
    }
}

int main(){
    int N;
    cin >> N;
    getchar();
    while(N--){
        char biggest_node;
        cin >> biggest_node;
        //cnt = biggest_node - 'A';
        memset(vis, 0, sizeof(vis));
        node.clear();
        cnt = 0;
        getchar();
        string S;
        while(getline(cin ,S) && S != ""){
            
            adj[S[0]].insert(S[1]);
            adj[S[1]].insert(S[0]);  
            
        }
        // for(int i = 'A'; i <= biggest_node; i++){
        //     cout << char(i) << " : "; 
        //     for(auto C : adj[i]){
        //         cout << C << ' ';
        //     }
        //     cout << endl;
        // }
        for(int i = 'A'; i <= biggest_node; i++){
            if(vis[i] == false){
                //cout << char(i) << endl;
                cnt++;
            }
            dfs(i);
        }
        cout << cnt << endl;
        if(N != 0)cout << endl;
        for(int i = 'A'; i <= biggest_node; i++){
            adj[i].clear();
        }
    }
    //cout << endl;
    
    return 0;
}


