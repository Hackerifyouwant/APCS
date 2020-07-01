#include<iostream>
#include<map>
#include<algorithm>
#include <numeric>

#define ll long long
#define endl '\n'

using namespace std;

int Gcd(int x, int y){
    if(y == 0)return x;
    return Gcd(y, x % y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        string S; cin >> S;
        map<char,int> cnt;
        for(int i = 0; i < N; i++)cnt[S[i]] ++;
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            int nc = Gcd(i, K);
            int percyc = i / nc;
            for(auto c : cnt){
                nc -= c.second / percyc;
            }
            if (nc <= 0) ans = i;
            cout << ans << endl;
        }
        cout << ans << endl;
    }
	
    return 0;
}