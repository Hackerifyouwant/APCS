#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        int p[20005];
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        sort(p, p + n);
        int ans = 0;
        for(int i = n - 3; i >= 0; i -= 3){
            ans += p[i];
        }
        cout << ans << endl;
    }

    return 0;
}