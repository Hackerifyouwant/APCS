#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

#define ll long long
#define endl '\n'
#define MAX 1000005 

using namespace std;

vector<ll> NN;
ll nod[MAX];
ll prime_c = 0;
ll prime_[MAX];
ll tbl[MAX];

// int NOD(int x){
//     ll X = x;
//     if(nod[x] != 0)return nod[x];
//     ll i = 0;
//     ll count = 1;
//     ll ans = 1;
//     while(x > 1){
//         while(x % prime_[i] == 0){
//             count ++;
//             x /= prime_[i];
//         }
//         ans *= count;
//         count = 1;
//         i++;
//     }
//     nod[X] = ans;
//     return ans;
// }
int NOD(int n) {
    int ans = 1, cnt = 0, i;
    for(i = 0; i < prime_c && prime_[i] * prime_[i] <= n; i++) {
        if(n%prime_[i] == 0) {
            cnt = 0;
            while(n % prime_[i] == 0)
                cnt++, n /= prime_[i];
            ans *= cnt + 1;
        }
    }
    if(n != 1)  ans *= 2;
    return ans;
}




int main(){
    for(ll i = 2; i < 50000; i++){
        if(tbl[i] == 0){
            prime_[prime_c] = i;
            prime_c++;
        }
        for(ll j = i + i; j < 50000; j += i){
            tbl[j] = 1;
        }
    }
    //NOD(MAX);
    NN.push_back(1);
    for(ll i = 1; i <= 65005; i++){
        NN.push_back(NN[i - 1] + NOD(NN[i - 1]));
        //cout << NN [i] << endl;
    }
    ll T;
    cin >> T;
    for(ll j = 0; j < T; j++){
        ll A, B;
        cin >> A >> B;

        cout << "Case " << j + 1 << ": ";
        cout << distance(lower_bound(NN.begin(), NN.end(), A) , upper_bound(NN.begin(), NN.end(), B)) << endl;
    }

    return 0;
}