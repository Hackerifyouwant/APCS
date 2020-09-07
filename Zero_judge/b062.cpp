#include<iostream>
#include<queue>

#define ll long long
#define endl '\n'

using namespace std;

int martix[55][55];

int step[55];
int ans;
int m;


int main(){
    while(cin >> m){
        memset(martix, 0, sizeof(martix));
        memset(step, 0, sizeof(step));
        ans = 0;
        for(int i = 1; i <= m; i++){
            string s;
            cin >> s;
            for(int j = 0; j < s.size(); j++){
                martix[i][j + 1] = int(s[j] - '0');
            }
        }
        int x, y, N;
        cin >> x >> y >> N;
        N++;
        queue<int> Q;
        Q.push(x);
        while(!Q.empty()){
            int tmp = Q.front();
            Q.pop();
            cout << " && " << tmp << " " <<step[tmp] << endl;
            if(step[tmp] <= N){
                if(tmp == y){
                    ans++;
                }
                for(int i = 1; i <= m; i++){
                    if(martix[tmp][i] == 1){
                        cout << i << endl;
                        step[i] = step[tmp] + 1;
                        Q.push(i);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}