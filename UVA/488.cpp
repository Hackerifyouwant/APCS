#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == EOF)return 0;
        for(int i = 0; i < n; i++){
            int A, F;
            cin >> A >> F;
            for(int j = 0; j < F; j++){
                for(int k = 0; k < A; k++){
                    for(int m = 0; m < k; m++){
                        cout << k;
                    }
                    cout << endl;
                }
                for(int k = A; k > 0; k--){
                    for(int m = 0; m < k; m++){
                        cout << k;
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    
    return 0;
}