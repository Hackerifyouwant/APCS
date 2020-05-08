#include<iostream>

#define ll unsigned long long
#define endl '\n'

using namespace std;

int negative = 1;

bool check(ll N){
    if(N > 6227020800){
        cout << "Overflow!" << endl;
        return 0;
    }
    else if(N < 10000){
        cout << " Underflow!" << endl;
        return 0;
    }else{
        return 1;
    }
}

ll Factorial_(int n){
    ll N;
    if(n == 1)return 1;
    N = n * Factorial_(n - 1);
    if(check(n))return 0;
    return n * Factorial_(n - 1);
}

ll Factorial(int n){
    ll N;
    if(n == 1)return 1;
    N = n * Factorial(n - 1);
    negative *= negative;
    //cout << N * negative << endl;
    //if(check(N))return 0;
    return n * Factorial(n - 1);
}

int main(){
    long long n;
    while(cin >> n){
        negative = 1;
        if(n < 0){
            negative = -1;
            n *= -1;
            ll F = Factorial(n);
            cout << F << endl;
        }else{
            ll F = Factorial_(n);
            cout << F << endl;
        }
    }


    return 0;
}