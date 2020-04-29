#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n,count = 0;
    while(cin >> n){
        if(n == 0)return 0;
        int sum = 0, averge = 0, ans = 0;
        int arr[105];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        averge = sum / n;
        for(int i = 0; i < n; i++){
            if(arr[i] > averge){
                ans += (arr[i] - averge);
            }
        }

        cout <<"Set #" << ++count << endl;
        cout << "The minimum number of moves is "<< ans << "." << endl << endl;
    }

    return 0;
}