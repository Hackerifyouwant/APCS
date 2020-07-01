#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int map[105][105];
int column[105];
int row;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m ,a , b;
        cin >> n >> m >> a >> b;

        for(int i = 0; i < m; i++)
            column[i] = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                map[i][j] = 0;

        if(n * a == m * b){
            int c = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < a; j++){
                    map[i][c] = 1;
                    c++;
                    if(c == m)c = 0;
                }
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m && row < a; j++){
                    cout << map[i][j];
                }
                cout << endl;
            }    
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}