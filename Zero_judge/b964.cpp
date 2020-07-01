#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n, arr[35];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int worst = 1e9, best = -1e9;
    for(int i = 0; i < n; i++){
        if(arr[i] >= 60){
            worst = min(worst, arr[i]);
        }
        if(arr[i] < 60){
            best = max(best, arr[i]);
        }
    }
    if(best == -1e9)cout << "best case" << endl;
    else cout << best << endl;

    if(worst == 1e9)cout << "worst case" << endl;
    else cout << worst << endl;    


    return 0;
}