#include<iostream>
#include<algorithm>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

ll value[202][202];
ll dp[202][202];

int main(){
    int  N, M, bit[202];
	char str[202];
	while(cin >> N){
        while(N -- ){
            cin >> str;
            M = strlen(str);
            for(int i = 0; i < M; i++){
                bit[i + 1] = str[i] - '0';
            }

            for (int i = 1; i <= M; ++ i) {
                for (int j = 1; j <= M; ++ j) {
                    dp[i][j] = 0LL;
                    value[i][j] = 0LL;
                }
            }

            for (int i = 1; i <= M; ++ i) {
                value[i][i] = bit[i];
                int flag = 0;
                for (int j = i + 1; j <= M; ++ j) {
                    value[i][j] = value[i][j - 1] * 10LL + bit[j];
                    if (flag || value[i][j] >= 2147483648LL) {
                        value[i][j] = 0LL;
                        flag = 1;
                    }
                }
            }

            for (int w = 1; w <= M; ++ w) {
                for (int s = 1; s <= M - w + 1; ++ s) {
                    //w是範圍
                    //s是起點
                    //e是終點
                    int e = s + w - 1;
                    dp[s][e] = value[s][e];
                    for (int k = s; k < s + w - 1; ++ k) {
                        dp[s][e] = max(dp[s][e], dp[s][k] + dp[k + 1][e]);
                    }
                }
            }

            cout << dp[1][M] << endl;
        }
    }
    return 0;
}