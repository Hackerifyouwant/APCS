#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;
    
ll arr[10000005];

int main(){
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}