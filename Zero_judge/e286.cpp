#include<iostream>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int arr[4];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int a;
            cin >> a;
            arr[i] += a;
        }
    }
    cout << arr[0] << ":" << arr[1] << endl;
    cout << arr[2] << ":" << arr[3] << endl;
    if(arr[0] > arr[1] && arr[2] > arr[3]){
        cout << "Win" << endl;
    }else if(arr[0] < arr[1] && arr[2] < arr[3]){
        cout << "Lose" << endl;
    }else{
        cout << "Tie" << endl;
    }

    return 0;
}
