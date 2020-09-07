#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;


struct Edge{
    int u, v, w;
};

int n, m, p[100005];
vector<Edge> edge;
int todo;
ll ans;

bool cmp(Edge l, Edge r){
    return l.w < r.w;
}

int find(int x){
    if(p[x] == x)return x;
    return p[x] = find(p[x]);
}

int main(){
    while(cin >> n >> m && n != EOF){
        todo = n - 1;
        ans = 0;
        edge.clear();
        Edge E;
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        for(int i = 0; i < m; i++){
            cin >> E.u >> E.v >> E.w;
            edge.push_back(E);
        }
        sort(edge.begin(), edge.end(), cmp);
        for(auto tmp : edge){
            int gx, gy;
            gx = find(tmp.u);
            gy = find(tmp.v);
            if(gx == gy)continue;
            else{
                p[gy] = gx;
                todo -= 1;
                ans += tmp.w;
            }
        }
        if (todo == 0) cout << ans << endl;
        else cout << "-1" << endl;
    }
    return 0;
}