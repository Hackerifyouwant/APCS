#include<iostream>
#include<algorithm>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

struct node{
    int R,C;
}X[11];
 
int DP[11][12];
int DI[11][12];

void print(int l, int s){
    if (l > 1) {
        cout << "(";
        print(DI[l][s], s);
        cout << " x ";
        print(l - DI[l][s], s + DI[l][s]);
        cout << ")";
    }else cout << "A" << s;
}



int main(){
    int n, t = 1;
    while ( cin >> n && n ) {
        for ( int i = 1; i <= n ; i++){
            cin >> X[ i ].R >> X[ i ].C;
        }
        memset(DP, 0, sizeof(DP));
        for (int l = 2; l <= n; l++){
            for (int s = 1; s + l - 1 <= n; s++){
                DP[l][s] = 1e9;
                for (int k = 1; k < l; k++){
                    //cout << l << " " << s << " " << k << " " << l - k << " " << s + k << " " << s + l - 1 << endl;
                    int Temp = DP[k][s] + DP[l - k][s + k] + X[s].R * X[s + k].R * X[s + l - 1].C;
                    if(DP[l][s] > Temp){
                        DP[l][s] = Temp;
                        DI[l][s] = k;
                    }
                }
                //cout << endl;
            }
            //cout << endl;
        }
        cout << "Case " << t++ << ": ";
        print( n, 1 );
        cout << endl;
    }
    return 0;
}