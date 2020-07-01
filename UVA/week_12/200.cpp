#include<iostream>
#include <string>
#include <vector>

#define ll long long
#define endl '\n'

using namespace std;

vector<char> ans;
vector<char> toPoint[100];
int visit[100];
int deg[100];
void DFS(char n){
    if(visit[n] == 1)return ;
    visit[n] = 1;
    cout << n  << " " << visit[n] << " : " << endl;
    for(char next : toPoint[n]){
        cout << next << " " << endl;
        if(visit[next] != 2){
            DFS(next);
        }
    }
    visit[n] = 2;
    ans.push_back(n);
}

int main(){
    string a, b;
    cin >> a;
    while(cin >> b && b != "#"){
        int l;
        if(a.size() > b.size()){
            l = b.size();
        }else {
            l = a.size();
        }
        for(int i = 0; i < l; i++){
            if(deg[a[i]] == 0)deg[a[i]] = 1;
            if(deg[b[i]] == 0)deg[b[i]] = 1;
            if (b[i] != a[i]) {
                toPoint[a[i]].push_back(b[i]);
                deg[b[i]] = 2;
                break;
            }
        }
        a = b;
    }
    for (char i = 'A'; i <= 'Z'; ++i){
        if (deg[i] == 1)DFS(i);
    }
    for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter){
        cout << *iter;
    }
    cout << endl;
        
    return 0;
}