#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int N;
    while(cin >> N){
        int arr[1005];
        for(int i = 0; i < N; i++){
            cin >> arr[i];    
        }
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N - i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    cnt++;
                }
            }
        }
        cout << "Minimum exchange operations : " << cnt << endl;
    }
    return 0; 
}