#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

vector <ll> pf;
ll cnt;
ll min_ans;

void prime_factor(ll n){
    if(n < 10){
        pf.push_back(n);
        ll ans = 0;
        for(ll i = 0; i < pf.size(); i++){
            ans += pf[i] * pow(10, pf.size() - i - 1);
        }
        min_ans = min(min_ans, ans);

        pf.pop_back();

        return ;
    }
    for(int i = 9; i >= 2; i--){
        if(n % i == 0){
            pf.push_back(i);
            prime_factor(n / i);
            pf.pop_back();
        
        }
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        ll N;
        cin >> N;
        if(N < 10)cout << N << endl;
        else{
            min_ans = 1e18;
            cnt = 0;
            prime_factor(N);
            if(min_ans == 1e18)cout << -1 << endl;
            else cout << min_ans << endl;
        }
    }
    return 0;
}