#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;


int arr[25];

int main(){
    int T;
    cin >> T;
    while(T--){
        int N; 
        cin >> N;
        fill(arr, arr + N, 0);
        for(int i = 0; i < 4; i++){
            cin >> arr[i];
        }
        for(int i = 4; i < N; i++){
            arr[i] = arr[i - 4] + arr[i - 1];
        }
        sort(arr, arr + N);
        // for(int i = 0; i < N; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        cout << arr[N / 2] << endl;
    }


    return 0;
}