#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n, R;
    while(cin >> n >> R){
        vector <int> survive(n + 1, 0);
        for(int i = 0; i < R; i++){
            int a;
            cin >> a;
            survive[a] = 1;
        }
        if(n == R)cout << "*" << endl;
        else{
            for(int i = 1; i <= n; i++){
                if(survive[i] == 0)cout << i  << " ";
            }
            cout << endl;
        }
    }
    return 0;
}