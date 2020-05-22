#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'
#define maxn 100000

using namespace std;

ll ledder[10000005];

int main(){
    ledder[0] = 3;
    for(int i = 1; i < maxn; i++){
        ledder[i] = ledder[i - 1] + pow(2, i + 1);
    }
    
    ll t;
    
    cin >> t;
    for(int i = 0; i < t; i++){
        ll n;
        cin >> n;
        ll k = 2;
        ll x = 1;
        ll sum = x;
        int j = 0;
        while(n % ledder[j] != 0){
            j++;
        }    
        cout << n / ledder[j] << endl;
        // while(sum != n){
        //     while(sum < n){
        //         sum += x * pow(2,k - 1);
        //         k++;
        //         if(sum == n)break;
        //     }
        //     if(sum == n)cout << x << endl;
        //     else {
        //         x++;
        //         sum = x;
        //         k = 2;
        //     }
        // }

    }    


    return 0;
}