#include<iostream>

#define ll long long 
#define endl '\n'

using namespace std;

int main(){
    int dp[77] = {0, 1, 2, 2};
    for(int i = 4; i < 77; i++){
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    int n;
    while(cin >> n && n != EOF){
        cout << dp[n] << endl;
    }

    return 0;
}