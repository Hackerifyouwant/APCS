#include<iostream>
#include<algorithm>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

int arr[10005], dp[10005];

int main(){
    int N;
    while(cin >> N && N != 0){
        
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        memset(dp, 0, sizeof(dp));
        int win = 0;
        dp[0] = 0;
        for(int i = 1; i < N; i++){
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
            win = max(win, dp[i]);            
        }
        if(win > 0){
            cout << "The maximum winning streak is " << win << "." << endl; 
        }else{
            cout << "Losing streak." << endl;
        }
        

    }
    return 0;
}
