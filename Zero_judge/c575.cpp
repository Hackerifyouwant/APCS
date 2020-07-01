#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

ll N, K;
ll P[50005];
    

bool check(int dis){
    int start = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(P[start] + dis < P[i]){
            start = i;
            cnt++;
        }
    }
    //cout << cnt << endl;
    return cnt < K;
}

int main(){
    cin >> N >> K;
    for(ll i = 0; i < N; i++){
        cin >> P[i];
    }
    sort(P, P + N);
    int l = 0;
    int r = P[N - 1] - P[0];
    int mid;
    while(l < r){
        mid = (l + r) / 2;
        //cout << l << " "  << mid << " " << r << endl;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << r << endl;


    return 0;
}