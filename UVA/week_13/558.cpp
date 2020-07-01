// #include<iostream>
// #include<algorithm>

// #define ll long long
// #define endl '\n'
// #define N 2001
// #define MAX 1e9

// using namespace std;

// int a[N], b[N], t[N];
// bool BellmanFord(int n, int m){
//     int d[n];
//     //maintain這個表格
//     fill(d, d + n, MAX);
//     d[0] = 0;

//     for(int i = 0; i < n - 1; i++){
//         for(int j = 0; j < m; j++){
//             if(d[a[j]] != MAX){
//                 if(d[a[j]] + t[j] < d[b[j]]){
//                     d[b[j]] = d[a[j]] + t[j];
//                 }
//             }
//         }
//     }

//     for (int j = 0; j < m; j++){
//         if (d[a[j]] + t[j] < d[b[j]]){
//             return true;
//         }         
//     }
//     return false;
// }

// int main(){
//     int c;
//     cin >> c; 
//     while(c--){
//         int n, m;
//         cin >> n >> m;
//         for(int i = 0; i < m; i++){
//             cin >> a[i] >> b[i] >> t[i];
//         }    
//         if(BellmanFord(n, m))cout << "possible" << endl;
//         else cout << "not possible" << endl;

//     }
//     return 0;
// }
#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'
#define N 2001
#define MAX 1e9

using namespace std;

struct Edge{
    int x, y, l;
}edge[N];

bool BellmanFord(int n, int m){
    int d[n];
    //maintain這個表格
    fill(d, d + n, MAX);
    d[0] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            if(d[edge[j].x] != MAX){
                if(d[edge[j].x] + edge[j].l < d[edge[j].y]){
                    d[edge[j].y] = d[edge[j].x] + edge[j].l;
                }
            }
        }
    }

    for (int j = 0; j < m; j++){
        if (d[edge[j].x] + edge[j].l < d[edge[j].y]){
            return true;
        }         
    }
    return false;
}

int main(){
    int c;
    cin >> c; 
    while(c--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            cin >> edge[i].x >> edge[i].y >> edge[i].l;
        }    
        if(BellmanFord(n, m))cout << "possible" << endl;
        else cout << "not possible" << endl;

    }
    return 0;
}