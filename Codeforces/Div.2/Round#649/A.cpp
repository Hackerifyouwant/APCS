#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector <int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        } 
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum % x) ans = max(ans, i + 1);
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += a[i];
            if (sum % x) ans = max(ans, n - i);
        }
        if (ans == 0) ans = -1;
        cout << ans << endl;
    }
}
 