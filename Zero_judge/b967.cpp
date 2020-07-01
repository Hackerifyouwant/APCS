#include<iostream>
#include <deque>
#include <algorithm>
#include <string.h>
#include <vector>

#define MAX 100001
#define ll long long
#define endl '\n'

using namespace std;

vector<int> adj[MAX];
int used[MAX];


void dfs(int x, int d) {
	for (auto c : adj[x]){
		if (used[c] == 0){
			used[c] = d + 1;
			dfs(c, d + 1);
		}
	}
}

int main(){
    int N;
    int node, Max;
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> N){
        for(int i = 0; i < N; i++){
            adj[i].clear();
        }
        memset(used, 0, sizeof(used));

        for(int i = 0; i < N - 1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        used[0] = 1;
		dfs(0, 1);  
		Max = -1;
        for (int i = 0; i < N; i++) {
			if (used[i] > Max) {
				Max = used[i];
				node = i;
			}
		}
        memset(used, 0, sizeof(used));
        used[node] = 1;
		dfs(node, 1);  
		for (int i = 0; i < N; i++) {
			if (used[i] > Max) {
				Max = used[i];
			}
		}
        cout << Max - 1 << endl;
    }

    return 0;
}