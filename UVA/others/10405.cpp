#include<iostream>
#include<algorithm>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;


int dp[1005][1005];

int main(){
    string S1, S2;
    while(getline(cin ,S1)){
        getline(cin, S2);
        memset(dp, 0 , sizeof(dp));
        for(int i = 1; i <= S1.size(); i++){
            for(int j = 1; j <= S2.size(); j++){
                if(S1[i - 1] == S2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[S1.size()][S2.size()] << endl;
    }

    return 0;
}