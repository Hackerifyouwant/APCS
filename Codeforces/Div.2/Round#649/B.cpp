#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector <int> ans;
        ans.push_back(0);
        for (int i = 1; i < n - 1; i++) {
            if (a[i - 1] < a[i] && a[i] < a[i + 1]) continue;
            if (a[i - 1] > a[i] && a[i] > a[i + 1]) continue;
            ans.push_back(i);
        }
        ans.push_back(n - 1);
        cout << ans.size() << endl;
        for (int id : ans) {
            cout << a[id] << ' ';
        }
        cout << endl;
    }
}
 