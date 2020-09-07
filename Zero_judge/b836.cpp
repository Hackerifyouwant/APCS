#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n, m;
    while(cin >> n >> m){
        if(m == 0){
            cout << "Go Kevin!!" << endl;
            continue;
        }
        ll cnt = 1;
        ll ans = 1;
        while(ans < n){
            cnt += m;
            ans += cnt;
        }
        if(ans == n)cout << "Go Kevin!!" << endl;
        else cout << "No Stop!!" << endl;
    }


    return 0;
}