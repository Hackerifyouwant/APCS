#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M, K;
int w[1005], v[1005];
 
bool cmp(double x, double y){
    return x > y;
}
 
bool check(double m){
    double a[N];
    for (int i = 0; i < N; i++){
        a[i] = v[i] - m * w[i];
    }
    sort(a, a + N, cmp);
    double sum = 0.0;
    for (int i = 0; i < K; i++){
        sum += a[i];
    }
    return sum >= 0.0;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }
    while (M--){
        cin >> K;
        double L = 0.0;
        double R = 1e18;
        while (R - L > 0.0001){
            double m = (L + R) / 2.0;
            if (check(m)){
                L = m;
            } else {
                R = m;
            }
        }
        cout << fixed << setprecision(2) << L << "\n";
    }
    return 0;
}