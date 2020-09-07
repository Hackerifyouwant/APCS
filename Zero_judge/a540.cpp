#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int N;
    while(cin >> N && N != 0){
        int arr[10005];
        int dp[10005];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        int ans = -1e9;
        for(int i = 0; i < N; i++){
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
            ans = max(dp[i], ans);
        }
        if(ans <= 0){
            cout << "Losing streak." << endl;
        }else{
            cout << "The maximum winning streak is " << ans << "." << endl;
        }


    }

    return 0;
}