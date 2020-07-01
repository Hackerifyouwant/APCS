#include<iostream>
#include <stdio.h>
#include <string.h>
#include<vector>


#define ll long long
#define endl '\n'
#define MAX 102

using namespace std;

int N, T;
//int a[MAX][MAX];
vector<int> a[105];
int v[MAX];

int dfs(int u){
    int i,c;
    c = 0;
    v[u] = 1;
    for(auto C : a[u]){
        if(v[C] == 0){
            c++;
            c += dfs(C);
        }
    }
   return c;
}

int main(){
    int i, j, t, max, max_i;
    while(cin >> N && N != 0){
        for(i = 0; i <= N; i++) 
            for(j = 0; j <= N; j++)
                a[i].clear();
        for(i = 1; i <= N; i++){
            cin >> T;
            for(j = 0; j < T; j++){
                cin >> t;
                a[i].push_back(t);
            }
        }
        max = -1;
        for(i = 1; i <= N; i++){
            for(j = 0; j <= N; j++) 
                v[j]=0;
            t = dfs(i);
            if(t > max){
                max = t; 
                max_i = i;
            }
        }
        cout << max_i << endl;
    }
    return 0;
}