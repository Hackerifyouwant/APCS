#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;

map<int, vector<int> > adj;
//vector<int> adj[105];
queue<int> Q;
map<int, bool>vis;
int nxt;
set<int> set_node;
int segment[10005];

int  main(){
    int N;
    int cnt = 1;
    while(cin >> N && N != 0){
        int a, b;
        set_node.clear();
        map<int, vector<int> >::iterator itr;
        for(itr = adj.begin(); itr != adj.end(); itr++){
            itr->second.clear(); 
        }
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            set_node.insert(a);
            set_node.insert(b);
        }
        while(cin >> a >> b){
            if(a == 0 && b == 0)break;

            int node = set_node.size();
            int ansb = b;
            
            while(!Q.empty())Q.pop();
            vis.clear();
            Q.push(a);
            vis[a] = 1;
            if(set_node.find(a) != set_node.end())node--;
            int cntt = 0;
            memset(segment, 0, sizeof(segment));
            segment[cntt] = 1;
            while(!Q.empty()){
                if(b == 0)break;
                nxt = Q.front();
                Q.pop();
                
                
                for(auto c : adj[nxt]){
                    if(vis[c] == 0){
                        Q.push(c);
                        segment[cntt + 1]++;
                        node--;
                        vis[c] = 1;
                        //cout << " && " << c << ' ';
                    }
                }
                //cout << segment[cntt] << endl;
                segment[cntt]--;
                if(segment[cntt]== 0){
                    b--;
                    cntt++;
                }
            }
            cout << "Case " << cnt++ << ": " << node << " nodes not reachable from node " << a << " with TTL = " << ansb << "." << endl;
        }
        getchar();
        
    }

    return 0;
}

