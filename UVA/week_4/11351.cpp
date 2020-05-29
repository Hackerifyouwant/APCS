#include<iostream>

#define ll long long
#define endl '\n'


using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k, ans = 0;
        cin >> n >> k;  
        for(int i = 1; i <= n; i++){
            ans = (ans + k) % i;
            cout << ans << endl;
        }
        cout << "Case " << i + 1 << ": " << ans + 1 << endl;
    }
    

    return 0;
}