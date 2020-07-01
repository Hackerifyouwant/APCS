#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n /= 2;
        ll n2 = n + 1;
        ll n3 = 2 * n + 1;
        ll sum = (n * n2 * n3 / 6) * 8; 
        cout << sum << endl; 
    }
    return 0;
}