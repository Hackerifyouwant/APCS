#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int arr[1000005];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int ans;
        int cnt = 0;
        int p;
        if(n % 2 == 0){
            ans = arr[n / 2 - 1];
            cnt = 2;
            p = arr[n / 2] - arr[n / 2 - 1] + 1;
            for(int i = 0; i < n; i++){
                if(arr[i] == ans && i != n / 2 - 1 && i != n / 2)cnt++;
            }   
        }else{
            ans = arr[(n - 1) / 2];
            cnt = 1;
            p = 1;
            for(int i = 0; i < n; i++){
                if(arr[i] == ans && i != (n - 1)/ 2)cnt++;
            } 
        }
        
        cout << ans << " " << cnt << " " << p << endl;
        

    }

    return 0;
}