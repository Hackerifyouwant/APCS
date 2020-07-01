#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n, Min = 1e9, Max = -1e9;
    vector<int>arr(100000005, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        fill(arr.begin() + l, arr.begin() + r, 1);
        Min = min(Min , l);
        Max = max(Max, r);
    }
    int sum = 0;
    for(int i = Min; i <= Max; i++){
        if(arr[i] == 1){
            sum ++;
        }
    }
    cout << sum << endl;

    return 0;
}