#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll N, M;
    while(cin >> N >> M){
        if(N == 0 && M == 0)break;
        int nm = M;
        int nn = N;
        M = min((N - M), M);
        ll c = 1;
        for(ll i = 0; i < M; i++){
            c = c * N / (i + 1);
            //cout << "&& " << N << " " << i + 1 << " " << c << endl;
            N --;
            //cout << c << endl;
        }
        cout << nn << " things taken "<< nm << " at a time is " << c << " exactly." << endl;
        //cout << n / m << endl;
    }

    return 0;
}