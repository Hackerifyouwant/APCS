#include<iostream>
#include<queue>
#include<vector>
#include<queue>
#include<algorithm>

#define ll long long
#define endl '\n'
#define N 20000

using namespace std;

struct Node
{
    int v, w;
    Node(){}
    Node(int vv, int ww) :v(vv), w(ww){}
    bool operator<(const Node& a)const{return w > a.w; }//小的優先
};

vector<Node>list[N];//adjacent list
int dijkstra(int s, int goal, int n){
    bool isVisit[N] = {};
    int d[N];
    fill(d, d + n, 1e9);

    d[s] = 0;
    priority_queue<Node> PQ;
    PQ.push(Node(s, 0));

     while (true){
        int next = -1;
        //找到尚未加進連通塊的點
        while (!PQ.empty() && isVisit[next = PQ.top().v])PQ.pop();
        //如都加進去了或是目標節點已加入，則return
        if (next == -1 || next == goal) return d[goal];
        isVisit[next] = true;

        for (Node node : list[next]){
            //如尚未走過且該點比原cost好，則push進去
            if (!isVisit[node.v] && d[next] + node.w < d[node.v]){
                d[node.v] = d[next] + node.w;
                PQ.push(Node(node.v, d[node.v]));
            }
        }
    }
    return d[goal];
}

int main(){
    int Case;
    cin >> Case;
    for(int c = 0; c < Case; c++){
        int n, m, s, t, u, v, w;
        cin >> n >> m >> s >> t;
        for(int i = 0; i < n; i++){
            list[i].clear();
        }

        for (int i = 0; i < m; i++){
            cin >> u >> v >> w;
            list[u].push_back(Node(v, w));
            list[v].push_back(Node(u, w));
        }
        
        cout << "Case #" << c + 1 << ": ";
        int ans = dijkstra(s, t, n);
        if (ans == 1e9){
            cout << "unreachable" << endl;
        }else{
            cout << ans << endl;
        }
    }


    return 0;
}