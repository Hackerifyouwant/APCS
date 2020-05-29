#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        string S[105];
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> S[i];
        }
        bool B = 0;
        bool check = 0;
        for(int i = 0; i < m && B == 0; i++){
            for(int j = 0; j < 26; j++){
                string s = S[0];
                check = 0;
                s[i] = 'a' + j;
                for(int k = 0; k < n && check == 0; k++){
                    int cnt = 0;
                    for(int l = 0; l < m; l++){
                        if(s[l] != S[k][l])cnt++;
                    }
                    if(cnt > 1){
                        check = 1;
                        break;
                    }
                }
                if(check == 0){
                    cout << s << endl;
                    B = 1;
                    break;
                }
            }
        }
        if(check == 1)cout << -1 << endl;
        
    }
    return 0;
}