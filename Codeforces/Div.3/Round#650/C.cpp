#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while(T--) {
        int N, K; 
        cin >> N >> K;
        vector<int> inds; 
        inds.push_back(- K - 1);
        for(int i = 0; i < N; i++) {
            char C; 
            cin >> C;
            if (C == '1') inds.push_back(i);
        }
        inds.push_back(N + K);
        int ans = 0;
        
        for(int i = 0; i < inds.size() - 1; i++){
            int dist = inds[i + 1] - inds[i];
            dist -= 1 + K;
            if (dist >= K + 1) {
                ans += dist / (K + 1);
            }
        }
        cout << ans << endl;
 
    }
    return 0;
}