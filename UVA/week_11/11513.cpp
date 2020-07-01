#include <cstdio>
#include <map>
#include <iostream>
#include <queue>
#include <string>
 
#define PB push_back
 
using namespace std;
 
map<string, int> dist;
queue<string> q;
string t, s;
map<string, string> p, moves;
int temp;
 
void bfs() {
    int i, j;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        string u = q.front(); q.pop();
        for (i=0 ; i<3 ; i++) { 
            string v = u;
            for (j=0 ; j<3 ; j++) {
                if(j == 2){
                    v[i * 3 + j] = u[i * 3];
                }else{
                    v[i * 3 + j] = u[i * 3 + j + 1];
                }
                
            }
            cout << v << endl;
            if (!dist.count(v)) {
                dist[v] = dist[u] + 1;
                p[v] = u;
                moves[v] = string(1, 'H') + string(1, i+'1');
               
            }
        } 
        for (j=0 ; j<3 ; j++) { 
            string v = u;
            for (i=0 ; i<3 ; i++) {
                if(i == 0){
                    v[i * 3 + j] = u[2 * 3 + j];
                }else{
                    v[i * 3 + j] = u[(i - 1)* 3 + j];
                }
                
            }
            cout << v << endl;
            if (!dist.count(v)) {
                dist[v] = dist[u] + 1;
                p[v] = u;
                moves[v] = string(1, 'V') + string(1, j+'1');
                
            }
        } 
    }
}
 
void printPath(string u) {
    if (s == u) return;
    else {
        cout << moves[u].c_str();
       
        printPath(p[u]);
    }
}
 
int main() {
    s = "123456789";
    bfs();
 
    while (1) {
        t.clear();
        for (int i=0 ; i<3 ; i++) {
            for (int j=0 ; j<3 ; j++) {
                cin >> temp;
                
                if (temp == 0) return 0;
                t.push_back(temp + '0');
            }
        }
 
        if (s == t) {cout << 0 << endl; continue;}
         
        if (dist.count(t)) {
            cout << dist[t] << " ";
            printPath(t);
            
        }
        else {
            cout << "Not solvable";
            
        }
        cout << endl;
        
    }
}