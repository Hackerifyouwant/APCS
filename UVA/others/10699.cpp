#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'
#define N 1000001

using namespace std;



int main(){
    vector<int> prime;
    int tbl[N];
    for(int i = 2; i <= N; i++){
        if(tbl[i] == 0){
            prime.push_back(i);
        }
        for(int j = i + i; j <= N; j += i){
            tbl[i] = 1;
        }
    }

    int n;
    while(cin >> n && n){
        int ans = 0;
        int temp = n;
        for(int i = 0; i < prime.size() && n >= prime[i] * prime[i]; i++){
            if (n % prime[i] == 0){
                ans++;
                while (n % prime[i] == 0)n /= prime[i];
            }
        }
        if (n > 1)ans++;

        cout << temp << " : " << ans << endl;
    }

    return 0;
}