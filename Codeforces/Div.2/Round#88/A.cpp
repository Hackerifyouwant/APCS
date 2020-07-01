#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        int card;
        cin >> n >> m >> k;
        int winner = min(n / k, m);
        int theirs = ( (m - winner + k - 2) / (k - 1) );
        cout << winner - theirs << endl;
    }

    return 0;
}