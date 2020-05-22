#include<iostream>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;
map<int, vector<int> > V;

int main(){
    int n, m;
    int arr[100005];
    while(cin >> n >> m){
        V.clear();
        for(int i = 0; i < n; i++){
            int v;
            cin >> v;
            V[v].push_back(i + 1);
        }
        
        for(int i = 0; i < m; i++){
            int k, v;
            cin >> k >> v;
            if(V[v].size() < k)cout << 0 << endl;
            else cout << V[v][k - 1] << endl;
        }
    }
    return 0;
}

