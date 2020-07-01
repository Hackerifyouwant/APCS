#include<iostream>
#include<algorithm>

#define MAX 1000005
#define ll long long
#define endl '\n'

using namespace std;

struct Edge{
    int v1, v2;
    int cost;
}edge[MAX];

int p[MAX];

bool cmp(const Edge l, const Edge r){
    return l.cost < r.cost;
}

int findRoot(int a){
    if(p[a] == a)return a;
    return p[a] = findRoot(p[a]);
}


int kruskal(int N, int E){
    
    for(int i = 1; i <= N; i++){
        p[i] = i;
    }
    sort(edge, edge + E, cmp);
    
    int cost = 0;
    for(int i = 0, e = 0; i < E && e < N - 1; e++ , i++){
        
        while (findRoot(edge[i].v1) == findRoot(edge[i].v2))i++;

        p[findRoot(edge[i].v1)] = findRoot(edge[i].v2);

        cost += edge[i].cost;
    }
    return cost;
}

int main(){
    int N;
    bool first = true;
    while(cin >> N && N){
        int a, b, w;
        int old_cost = 0, new_cost;
        for(int i = 1; i < N; i++){
            cin >> a >> b >> w;
            old_cost += w;
        }
        int K, M;
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> edge[i].v1 >> edge[i].v2 >> edge[i].cost;
        }
        cin >> M;
        for(int i = 0; i < M; i++){
            cin >> edge[i + K].v1 >> edge[i + K].v2 >> edge[i + K].cost;
        }
        new_cost = kruskal(N, K + M);

        if(first){
            first = false;
        }else{
            cout << endl;
        }
        cout << old_cost << endl;
        cout << new_cost << endl;
    }


    return 0;
}


