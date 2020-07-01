#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, map[105][105];
        cin >> n;
        bool check = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                char c;
                cin >> c;
                if(c == '1')map[i][j] = 1;
                else map[i][j] = 0;
            }
        for(int i = 0; i < n - 1 && check == 0; i++)
            for(int j = 0; j < n - 1; j++)
                if(map[i][j] == 1 && map[i+1][j] == 0 && map[i][j+1] == 0){
                    cout << "NO" << endl;
                    check = 1;
                    break;
                }
        if(check == 0)cout << "YES" << endl;
    }
    return 0;
}