#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>

#define ll long long 
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        vector <int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector <int> ids;
        for (int i = 0; i < m; i++) ids.push_back(i);
        vector <vector <int> > ok;

        while (!ids.empty()) {
            int sum = 0;
            vector <int> go, l;
            for (int z : ids) {
                if (!b[z]) {
                    l.push_back(z);
                    sum++;
                } else {
                    go.push_back(z);
                }
            }
            for (int x : go) {
                for (int y : l) {
                    b[x] -= abs(x - y);
                }
            }
            ok.push_back(l);
            ids = go;
        }

        reverse(ok.begin(), ok.end());
        map <char, int> cnt;
        for (auto z : s) cnt[z]++;
        vector <char> ans(m);
        for (auto c : ok) {
            for (auto &t : cnt) {
                if (t.second >= (int)c.size()) {
                    t.second = 0;
                    for (int p : c) {
                        ans[p] = t.first;
                    }
                    break;
                }
                t.second = 0;
            }
        }
        for (int i = 0; i < m; i++) cout << ans[i];
        
        cout << endl;
    }
    return 0;
}
