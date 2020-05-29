#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;



int main(){
    int N, D, I, ans;
    
    cin >> N;
    for(ll i = 0; i < N; i++){
        cin >> D >> I;
        ans = 1;
        for(int i = 1; i < D; i++){
            if(I % 2 == 1){
                ans *= 2;
                I = (I + 1) / 2;
            }else{
                ans = ans * 2 + 1;
                I /= 2; 
            }
            //cout << ans << " " << I << endl;
        }
        cout << ans << endl;
    }
}



