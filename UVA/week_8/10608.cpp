#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int set[1000005];
int Group[1000005];

int findRoot(int x){
    if(set[x] == x)return x;
    return set[x] = findRoot(x);
}

void Union(int x, int y, int group){
    if(set[x] == set[y])return ;
    
    int gx = set[x], gy = set[y];
    Group[set[gy]] += Group[set[gx]];
    Group[set[gx]] = 0;
    for(int i = 1; i <= group; i++){
        if(set[i] == gx){
            set[i] = gy;
        }
    }
}

void Initial(int group){
    for(int i = 1; i <= group; i++){
        set[i] = i;
        Group[i] = 1;
    }   
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int N, M;
        cin >> N >> M;
        Initial(N);
        for(int j = 0; j < M; j++){
            int A, B;
            cin >> A >> B;
            Union(A, B, N);
        }
        int Max = -1e9;
        for(int j = 1; j <= N; j++){
            Max = max(Max, Group[j]);
        }
        cout << Max << endl;
    }
    return 0;
}
