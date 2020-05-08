#include<iostream>
#include<stdlib.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n, cal = 0, count[10005], arr[10005];
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    while(cin >> n){
        arr[cal++] = n;
        count[n]++;
        cout << cal << endl;
        if(cal == 9)break;
    }
    for(int i = 0; i < cal; i++){
        cout << arr[i] << count[arr[i]] << endl;
    }
    return 0;
}
