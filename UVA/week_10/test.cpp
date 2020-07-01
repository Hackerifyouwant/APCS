#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 1;  // a^0
    // ai => a^(2^i); bt => b 的替死鬼(為了保留 b 原本的值不被破壞)
    for (int ai=a, bt=b; bt>0; ai*=ai, bt>>=1){
        cout << ai << " " << bt << endl;
        if (bt & 1){  // b 的第 i 位元是 1{
            ans *= ai;  // a^(2^i) 的係數就會是 1； else 係數是 0
        }
    }
    cout << ans;
    return 0;
}