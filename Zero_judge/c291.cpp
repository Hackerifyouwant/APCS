#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int set[50005];
int group;
int N;

int find (int x){
    if(x == set[x])return set[x];
    else return set[x] = find(set[x]);
}

void Union(int x, int y){
    x = find(x), y = find(y);
    if(x == y)return;
    group--;
    set[x] = y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;
    group = N;
    for(int i = 0; i < N; i++){
        set[i] = i;
    }
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        Union(i, a);
    }
    cout << group << endl;
    

    return 0;
}
// #include<iostream>
// #include<vector>

// #define ll long long
// #define endl '\n'

// using namespace std;

// vector<int>adj[50005];
// bool used[50005];

// void dfs(int start){
//     used[start] = 1;
//     for(auto c : adj[start]){
//         if(!used[c])dfs(c);
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         int a;
//         cin >> a;
//         adj[i].push_back(a);
//         adj[a].push_back(i);
//     }
//     int group = 0;
//     for(int i = 0; i < n; i++){
//         if(!used[i]){
//             group++;
//             dfs(i);
//         }
//     }
//     cout << group << endl;
    

//     return 0;
// }