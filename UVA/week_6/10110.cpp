#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n, root;
    while(cin >> n && n != 0){
        root = sqrt(n);
        if(root * root == n)cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}