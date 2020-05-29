#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;


int set[100005];
int n, m, group;

void Union(int i, int j){
    if(set[i] == set[j])return;
    group--;
    int gx = set[i], gy = set[j];
    for(int i = 1; i <= n; i++){
        if(set[i] == gx){
            set[i] = gy;
        }
    }
}

int main(){
    int cnt = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        for(int i  = 1; i <= n; i++){
            set[i] = i;
        }
        group = n;
        for(int k = 0; k < m; k++){
            int i, j;
            cin >> i >> j;
            Union(i, j);
        }
        cout << "Case " << cnt++ << ": " << group << endl;
    }

    
    return 0;
}