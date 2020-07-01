#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int odd = 0, even = 0;
        int arr[105];
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0)even++;
            else odd++;
        }
        if(n % 2 == 0){
            if(even != odd || even != n / 2){
                cout << -1 << endl;
                continue;
            }
        }else{
            if(even - 1 != odd){
                cout << -1 << endl;
                continue;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % 2 != i % 2)cnt++;
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}