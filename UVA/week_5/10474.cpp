#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int N, Q, cnt = 1;
    while(cin >> N >> Q){
        if(N == 0 && Q == 0)break;
        int arr[10005];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr, arr + N);
        cout << "CASE# " << cnt++ << ":" << endl;
        for(int i = 0; i < Q; i++){
            int a;
            cin >> a;
            bool check = 0;
            for(int j = 0; j < N; j++){
                if(a == arr[j]){
                    cout << a << " found at " << j + 1 << endl; 
                    check = 1;
                    break;
                }
            }
            if(check == 0)cout << a << " not found" << endl;
        }
    }
    return 0;
}