#include<iostream>

#define ll long long
#define endl '\n'
#define N 101

using namespace std;

int main(){
    int C, S, Q;
    int Case = 0;
    int d[N][N];

    while(cin >> C >> S >> Q){
        if(C == 0 && S == 0 && Q == 0)break;

        for (int i = 0; i <= C; i++){
            for (int j = 0; j <= C; j++){
                d[i][j] = 1e9;
            }
        }
            
        for(int i = 0; i < S; i++){
            int c1, c2, decibel;
            cin >> c1 >> c2 >> decibel;
            d[c1][c2] = d[c2][c1] = decibel;
        }
        for(int k = 1; k <= C; k++){
            //選定點K
            for(int i = 1; i <= C; i++){
                for (int j = 1; j <= C; j++){
                    //選定點K後，更新表格
                    d[i][j] = d[j][i] = min(max(d[i][k], d[k][j]), d[i][j]);
                }
            }
        }
        if (Case)cout << endl;
        cout << "Case #" << ++Case << endl;

        for(int i = 0; i < Q; i++){
            int c1, c2;
            cin >> c1 >> c2;
            if (d[c1][c2] != 1e9){
                cout << d[c1][c2] << endl;
            }
            else{
                cout << "no path" << endl;
            }
        }
    }

    return 0;
}
