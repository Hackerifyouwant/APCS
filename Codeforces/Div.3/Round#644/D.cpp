#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'
#define MAX 105

using namespace std;


int main(){
    
    int t;
    cin >> t;
    while(t --){
        int n, k;
        int P = 0;
        cin >> n >> k;
        for(int i = 1; i < 40000; i++){
            if(n % i == 0){
                if(i <= k){
                    P = max(P, i);
                }
                if(n / i <= k){
                    P = max(P, n / i);
                }
            }
        }
        cout << n / P << endl;
    }
    return 0;
}