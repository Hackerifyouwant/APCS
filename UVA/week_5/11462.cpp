#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        int arr[2000005];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for(int i = 0; i < n; i++){
            if(i == n - 1)cout << arr[i];
            else cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
