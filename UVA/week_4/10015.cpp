#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'
#define Max 35000

using namespace std;

int tbl[Max];
int prime_[Max];
int prime_C = 0;
int index_ = 0;
int n;
bool vis[Max];

void prime(){
    for(int i = 2; i <= Max; i++){
        if(tbl[i] == 0){
            prime_[prime_C] = i;
            prime_C++;
        }
        for(int j = i + i; j <= Max; j += i){
            tbl[j] = 1;
        }
    }
}
int main(){
    prime();
    while(cin >> n && n != 0){
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + prime_[n-i]) % i;
        }

        cout << ans + 1 << endl;    
    }
    return 0;
}