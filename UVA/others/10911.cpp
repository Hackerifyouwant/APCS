#include<iostream>
#include<math.h>
#include<algorithm>
#include<iomanip>

#define ll long long
#define endl '\n'

using namespace std;

struct Student{
    int x, y;
    double getDis(Student& p){
        return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
    }
}student[16];


int main(){
    int N, i, Case = 1;
    double dp[1 << 16], dis[16][16];
    while(cin >> N && N){
        N *= 2;
        for(int i = 0; i < N; i++){
            string s;
            cin >> s >> student[i].x >> student[i].y;
        }
        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                dis[i][j] = student[i].getDis(student[j]);
            }
        }

        dp[0] = 0;
        
        for (int s = 1; s < (1 << N); s++) {
            dp[s] = 1e9;
            for (i = N - 1; i >= 0; i--){
                if (s & (1 << i))break;
            }
                
            for (int j = 0; j < i; j++){
                if (s & (1 << j)){
                    dp[s] = min(dp[s], dis[j][i] + dp[s ^ (1 << i) ^ (1 << j)]);
                }
            }
        }

        cout << fixed << setprecision(2) << "Case " << Case++ << ": " << dp[(1 << N) - 1] << endl;
    }
    return 0;
}