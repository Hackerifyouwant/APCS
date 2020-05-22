#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll a, b;
    while(cin >> a >> b){
        cout << (a^b) << endl;
    }
    return 0;
}