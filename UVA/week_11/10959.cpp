#include<vector>
#include<deque>
#include<iostream>
#include<map>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

map<int, vector<int> >adj;
deque <int> Q;
bool vis[1005];
int step[1005];


int main(){

    int N;
    cin >> N;
    while(N--){
        memset(step, 0, sizeof(step));
        memset(vis, false, sizeof(vis));
        int P, D;
        cin >> P >> D;

        for(auto c : adj){
            c.second.clear();
        }
        adj.clear();

        for(int i = 0; i < D; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        Q.clear();
        Q.push_back(0);
        step[0] = 0;

        while(!Q.empty()){
            int tmp = Q.front();
            vis[tmp] = 1;
            Q.pop_front();
            for(auto c : adj[tmp]){
                if(vis[c] == 0){
                    if(step[c] < step[tmp] || step[tmp] == 0)step[c] = step[tmp] + 1;
                    Q.push_back(c);
                }
            }
        }
        for(int i = 1; i < P; i++){
            cout << step[i] << endl;
        }
        if(N)cout << endl;
        
    }

    return 0;
}



