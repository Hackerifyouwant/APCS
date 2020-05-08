#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

ll B, P, M;

int times(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 != 0){
        return ((a % M) * times(a, b - 1)) % M;
    }
    int t = times(a, b / 2) % M;
    return ((t % M) * (t % M)) % M;

}

int main(){
    
    while(cin >> B >> P >> M){
        ll R = 1;
        R = times(B, P);
        cout << R << endl;
    }
    return 0;
}