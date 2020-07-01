#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        string s[105];
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        for(int i = 0; i < n; i++){
            cout << s[i] << endl;
        }
    }


    return 0;
}