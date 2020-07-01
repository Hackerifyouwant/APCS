#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, x, y;
    long long ans;
    vector <int> v;
    while (cin >> n){
        if (n == 0){
            cout << 0 << endl;
            continue;
        }
        v.clear();
        ans = 0;
        for (int i = 0; i < n; i++){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        while (v.size() >= 4){
            x = v[0] * 2 + v[v.size()-2] + v[v.size()-1];
            y = v[0] + v[1] * 2 + v[v.size()-1];
            ans += min(x, y);
            v.resize(v.size()-2);
        }
        if (v.size() == 3){
            for (int i : v){
                ans += i;
            }
        }else if (v.size() == 2){
            ans += v[1];
        }else{
            ans += v[0];
        }
        cout << ans << endl;
    }
}