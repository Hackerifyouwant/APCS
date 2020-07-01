#include<iostream>
#include<queue>
#include<sstream>
#include<algorithm>
#include<cstdio>

#define N 101
#define ll long long
#define endl '\n'

using namespace std;

bool lift[5][N];
int t[5];
int dijkstra(int tar, int n){
    struct Floor{
        int id, n, t;
        Floor(){}
        Floor(int _id, int _n, int _t) :id(_id), n(_n), t(_t){}
        bool operator<(const Floor& a)const{
            return t > a.t; 
        }//耗時少的較優先
    };

    bool isVisit[5][N] = {};//[lift][floor]
    int T[5][N];//從 0 層到各樓層所需的時間，不同電梯在同樓層的時間也不相同
    priority_queue<Floor> PQ;
    Floor next;

    for (int i = 0; i < 5; i++){
        fill(T[i], T[i] + N, 1e9);
    }
    for (int i = 0; i < n; i++){
        if (lift[i][0]){
            T[i][0] = 0;
            PQ.push(Floor(i, 0, 0));
        }
    }
       
    while(true){
        next.id = -1;
        //找到尚未遍歷的點
        while (!PQ.empty()){
            next = PQ.top();
            PQ.pop();
            if (!isVisit[next.id][next.n])break;
        }

        isVisit[next.id][next.n] = true;
        if (next.id == -1 || next.n == tar)break;

        for (int j = 0; j < n; j++){
            //遍歷所有該點可走且未走過的路徑
            if (lift[j][next.n] && !isVisit[j][next.n]){
                //如換一個電梯的cost還小於原點，則替換之，並且push進去
                if (next.t + 60 < T[j][next.n]){
                    T[j][next.n] = next.t + 60;
                    PQ.push(Floor(j, next.n, T[j][next.n]));
                }
            }
        }

        for (int j = 0; j < N; j++){
            if (lift[next.id][j] && !isVisit[next.id][j]){
                //時間計算
                //遍歷該點的所有子節點
                //計算cost
                int time = t[next.id] * (j - next.n);
                if (time < 0)
                    time *= -1;

                if (next.t + time < T[next.id][j]){
                    T[next.id][j] = next.t + time;
                    PQ.push(Floor(next.id, j, T[next.id][j]));
                }
            }
        }
    }    
    if(next.n == tar){
        return next.t;
    }
    return -1;
}

int main(){
    int n, tar;
    stringstream ss;
    while(cin >> n >> tar && n != EOF){
        for(int i = 0; i < 5; i++){
            fill(lift[i], lift[i] + N, false);
        }

        for(int i = 0; i < n; i++){
            cin >> t[i];
        }
        string str;
        getchar();
        for(int i = 0; i < n; i++){
            int temp = 0;
            getline(cin, str);
            ss.clear();
            ss << str;
            while(ss >> temp){
                lift[i][temp] = true;
                temp = 0;
            }    
        }
        int ans = dijkstra(tar, n);
        if(ans == -1)cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
}

