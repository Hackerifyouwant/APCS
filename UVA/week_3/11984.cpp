#include<iostream>
#include<iomanip>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        double C, d;
        cin >> C >> d;
        double F = (9 * C) / 5 + 32;
        F += d;
        C = (F - 32) * 5 / 9; 
        cout << "Case " << i + 1 << ": " << fixed << setprecision(2) << C << endl;
    }

    return 0;
}