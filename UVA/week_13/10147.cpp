#include<iostream>
#include<utility>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>

#define MAX 750
#define ll long long
#define endl '\n'

using namespace std;

typedef pair<int, int> Coord;

struct Node
{
    int a;//idx of coord[]
    double dis;
    Node(){}
    Node(int aa, double d) :a(aa), dis(d){}
    bool operator >(const Node& n)const{ return dis > n.dis; };
};

vector<Node> adjList[MAX];

double getDistance(Coord& a, Coord& b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
void prim(int n){
    int parent[MAX] = {};
    double d[MAX] = {};
    bool isVisit[MAX] = {}, flag = true;
    for (int i = 0; i < n; i++){
        d[i] = 1e9;
    }
    priority_queue<Node, vector<Node>, greater<Node> > PQ;
    PQ.push(Node(0, 0));
    d[0] = 0;

    for(int i = 0; i < n; i++){
        Node next;
        //找尚未在連通塊內的節點
        while(isVisit[(next = PQ.top()).a]){
            PQ.pop();
        }

        //新建的路
        if (next.dis){
            cout << parent[next.a] + 1 << " " << next.a + 1 << endl;
            flag = false;
        }

        isVisit[next.a] = true;
        //表示next.a已加入連通塊
        int size = adjList[next.a].size();
        //找子節點中cost最小的，並push進heap
        for (int k = 0; k < size; k++){
            Node node = adjList[next.a][k];
            if (!isVisit[node.a] && node.dis < d[node.a]){
                //如尚未加進連通塊且cost比之前找到的還小，就更新
                d[node.a] = node.dis;
                parent[node.a] = next.a;
                PQ.push(node);
            }
        }
    }
    if (flag)cout << "No new highways need" << endl;
}

int main(){
    Coord coord[MAX];
    int Case;

    cin >> Case;
    while(Case--){
        int n, m;
        cin >> n;
        for(int i = 0; i < n; i++){
            adjList[i].clear();
        }
        for(int i = 0; i < n; i++){
            cin >> coord[i].first >> coord[i].second;
        }

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                double dis = getDistance(coord[i], coord[j]);
                adjList[i].push_back(Node(j, dis));
                adjList[j].push_back(Node(i, dis));
            }
        }

        int a, b;
        cin >> m;

        for (int i = 0; i < m; i++){
            cin >> a >> b;
            adjList[a - 1].push_back(Node(b - 1, 0));
            adjList[b - 1].push_back(Node(a - 1, 0));
        }
        
        prim(n);

        if (Case)cout << endl;

    }

    return 0;
}