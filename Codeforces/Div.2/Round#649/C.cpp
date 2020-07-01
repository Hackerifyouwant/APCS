#include<iostream>
#include<algorithm>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    } 
    vector <int> have(n + 1);
    for (int i = 0; i < n; i++) {
        have[a[i]] = 1;
    }
    have[0] = 1;
    int lst = 0;
    vector <int> ans;
    int uk = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > lst) {
            ans.push_back(lst);
        }else {
            while (uk <= n && have[uk]){
                uk++;
            }
            ans.push_back(uk++);
        } 
        lst = a[i];
    }
    for (int x : ans){
        cout << x << ' ';
    } 
    return 0;
}