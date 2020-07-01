#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        string ans;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(i == s.size() - 1)ans += s[i];
            if(i % 2 == 0)ans += s[i];
        }
        cout << ans << endl;
    }
    return 0;
}