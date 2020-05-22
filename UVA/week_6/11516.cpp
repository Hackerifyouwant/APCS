#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>


#define ll long long
#define endl '\n'

using namespace std;

int map[1000005];
int n, m;

int greedy(double d){
    double tmp = map[0] + d * 2;
    int count = 1;
    for(int i = 0; i < m; i++){
        if(tmp < map[i]){
            tmp = map[i] + d * 2;
            count++;
        }
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n >> m;
        for(int j = 0; j < m; j++){
            cin >> map[j];
        }
        if(n >= m){
            cout << 0.0 << endl;
            continue;
        }
        sort(map, map + m);
        double l = 0;
        double r = map[m - 1] - map[0];
        double mid;
        while(r - l > 0.5){
            mid = (l + r) * 0.5;
            double result = greedy(mid);
            if(result <= n){
                r = mid;
            }else{
                l = mid;
            }
        }
        if(l - int(l) < 0.5)l = int(l) + 0.5;
        else if(l - int(l) > 0.5) l = int(l) + 1;
        
        cout << fixed << setprecision(1) << l << endl;

    }
    return 0;
}