#include<iostream>

//#define N 1000001
#define N 100
#define ll long long 
#define endl '\n'

using namespace std;

int factorial[N];
void solve(){
    for(int i = 0; i < N; i++){
        factorial[i] = 1;
    }
    factorial[1] = 0;
    for (int i = 2; i < N; i++){
        if (factorial[i] == 1){
            for (int j = 2; i * j < N; j++){
                factorial[i * j] = factorial[i] + factorial[j];
            }
        }
    }

    for (int i = 2; i < N; i++){
        factorial[i] += factorial[i - 1];
    }
}

int main(){
    int n;
    solve();
    while(cin >> n && n){
        cout << factorial[n] << endl;
    }
    return 0;
}