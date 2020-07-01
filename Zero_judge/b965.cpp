#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int r, c, m;
    while(cin >> r >> c >> m){
        vector< vector <int > > martix(r, vector<int>(c));
        int K[105];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> martix[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            cin >> K[i];
        }
        for(int i = m - 1; i >= 0; i--){
            int a;
            a = K[i];
            if(a == 0){
                //旋轉
                vector< vector<int> >new_martix(c, vector<int>(r));
                // for(int i = 0; i < c; i++){
                //     for(int j = r - 1, k = 0; j >= 0 && k < r; j--, k++){
                //         new_martix[i][k] = martix[j][i]; 
                //     }
                // }
                for(int i = c - 1, k = 0; i >= 0 && k < c; i--, k++){
                    for(int j = 0; j < r; j++){
                        new_martix[k][j] = martix[j][i];
                    }
                }
                swap(r , c);
                // for(int i = 0; i < r; i++){
                //     for(int j = 0; j < c; j++){
                //         cout << new_martix[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                martix = new_martix;
            }else{
                //翻轉
                reverse(martix.begin(), martix.end());
                
            }
            //cout << endl;
        }
        cout << r << " " << c << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(j == c - 1)cout << martix[i][j];
                else cout << martix[i][j] << " ";
            }
            cout << endl;
        }
    }
    

    return 0;
}