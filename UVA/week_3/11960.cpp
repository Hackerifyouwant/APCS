#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

vector <ll> prime;
ll tbl[1000005];
ll factor[1000005];

void prime_(int max){
    for(int i = 2; i <= max; i++){
        if(tbl[i] == 0){
            prime.push_back(i);
        }
        for(int k = i + i; k <= max; k+=i){
            tbl[k] = 1;
        }
    }
    for(int i = 1; i <= max; i++){
        cout << i << " " << tbl[i] << endl;
    }
}

int pri(int x){
    int sum;
    if(tbl[x] == 0){
        return 2;
    }else{
        for(int i = 0; i < prime.size(); i++){
            if(x % prime[i] == 0){
                x /= i;
                sum += 2;
            }
        }
    }
}


int main(){
    ll T;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    ll max_input = -1;
    for(int i = 0; i < T; i++){
        ll N;
        cin >> N;
        max_input = max(max_input, N);
    }
    prime_(max_input);

        
    return 0;
}