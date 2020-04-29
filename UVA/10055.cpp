#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    long long a,b;
    while(cin >> a >> b){
        // if(a == EOF || b == EOF)return 0;
        // if(a >= b)cout << a - b <<endl;
        // else cout << b - a << endl;
        long long d = abs(a - b); 
        cout << d << endl;
    }

    return 0;
}