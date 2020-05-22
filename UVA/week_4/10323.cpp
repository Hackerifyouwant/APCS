#include<stdio.h>
#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;
 
int main(){
    long long int n, ans, fac;
    int i, over;
 
    while(cin >> n){
        if(n < 0){
            n = 0 - n;
            if(n % 2 == 0){
                cout << "Underflow!" << endl;
            }else{
                cout << "Overflow!" << endl;
            }
        }else{
            fac = 1;
            over = 0;
            for(i = 1 ; i <= n ; i++){
                fac = fac * i;
                if(fac > 6227020800) {
                    cout << "Overflow!" << endl;
                    over++;
                    break;
                }
            }
            if(over == 0){
                if(fac < 10000){
                    cout << "Underflow!" << endl;
                }
                else{
                    cout << fac << endl;
                }
            }
        }
    }
    return 0;
}