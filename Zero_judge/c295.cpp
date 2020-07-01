#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int N, M, sum = 0;
    int Max[20];
    fill(Max, Max + 20, -1);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int a;
            cin >> a;
            Max[i] = max(Max[i], a);
        }
        sum += Max[i];
    }
    cout << sum << endl;
    bool chk = 0;
    for(int i = 0; i < N; i++){
        if(sum % Max[i] == 0){
            chk = 1;
            if(i == N - 1)cout << Max[i];
            else cout << Max[i] << " ";
        }
    }
    if(chk == 0)cout << "-1";
    cout << endl;
    return 0;
}