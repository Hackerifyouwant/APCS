#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    cout << arr[0] << " " << arr[1]<< " " << arr[2] << endl;
    if(arr[0] + arr[1] < arr[2])cout << "No" << endl;
    else if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]){
        cout << "Right" << endl;
    }else if(arr[0] * arr[0] + arr[1] * arr[1] > arr[2] * arr[2]){
        cout << "Acute" << endl;
    }else if(arr[0] * arr[0] + arr[1] * arr[1] < arr[2] * arr[2]){
        cout << "Obtuse" << endl;
    }
    return 0;
}