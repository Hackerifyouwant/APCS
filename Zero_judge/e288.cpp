#include<iostream>
#include <map>
#include <string.h>

#define ll long long
#define endl '\n'

using namespace std;

int m, n, l, a[38], ans;
long long mask, tmp;
string s;
map <long long, int> mp;

int alpha2int(char c){
    if (c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> m >> n){
        mp.clear();
        ans = 0;
        mask = 0;
        for (int j = 0; j < m; j++){
            mask |= (1LL << j);
        }
        for (int i = 0; i < n; i++){
            memset(a, 0, sizeof(a));
            cin >> s;
            l = (int)s.size();
            for (int j = 0; j < l; j++){
                a[alpha2int(s[j])] = 1;
            }
            tmp = 0;
            for (int j = 0; j < 38; j++){
                if (a[j]) tmp |= (1LL << j);
            }
            if (mp.count(tmp ^ mask)) ans += mp[tmp ^ mask];
            
            if (mp.count(tmp)) mp[tmp]++;
            else mp[tmp] = 1;
        }
        cout << ans << endl;
    }

    return 0;
}