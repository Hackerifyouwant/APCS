#include<iostream>
#include<cmath>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

int f(int n){
    if(n > 1){
        return f(n >> 1) + 1;
    }else{
        return 1;
    }
}

int main(){
    ll N;
    while(cin >> N){
        cout << f(N) << endl;
    }
    return 0;
}