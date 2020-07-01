#include <iostream>
#include <cmath>
#include<iomanip>

#define ll long long
#define endl '\n'

using namespace std;
 
int Case, n, x[20], y[20];
string s;
double dp[1<<16];
 
double dist(int a, int b){
    double ret = sqrt((x[a]-x[b]) * (x[a]-x[b]) + (y[a]-y[b]) * (y[a]- y[b]));
    return ret;
}
 
double solve(int mask){
    if (dp[mask] > -1) return dp[mask];
    if (!mask) return 0;
    double mn = 1e18;
    for (int i = 0; i < n; i++){
        if (!((1 << i) & mask)) continue;
        //找到第一個未組隊的
        for (int j = i + 1; j < n; j++){
            if (!((1 << j) & mask)) continue;
            //找到第二個未組隊的
            //將其設為組隊
            mn = min(mn, solve(mask ^ (1 << i) ^ (1 << j)) + dist(i, j));
        }
        break;
    }
    return dp[mask] = mn;
}
 
int main() {
    while (cin >> n){
        if (n == 0) break;
        n *= 2;
        for (int i = 0; i < n; i++){
            cin >> s;
            cin >> x[i] >> y[i];
        }
        for (int i = 0; i < (1<<n); i++){
            dp[i] = -1e18;
        }
        Case++;
        cout << fixed << setprecision(2) << "Case " << Case << ": " << solve((1 << n) - 1) << endl;
        
    }
}