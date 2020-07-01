#include<iostream>
#include<math.h>
#include<iomanip>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

double area(int a, int b, int c, int d, int e, int f){
    return  abs(0.5 * ( (a * d) + (c * f) + (b * e) - (b * c) - (d * e) - (a * f)) ) ;
}

int main(){
    int N;
    while(cin >> N){
        int x[205], y[205];
        for(int i = 0; i < N; i++){
            cin >> x[i] >> y[i];
        }
        double Max = -1e9;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                for(int k = j + 1; k < N; k++){
                    Max = max(Max, area(x[i], y[i], x[j], y[j], x[k], y[k]));
                }
            }
        }
        cout << fixed << setprecision(2) << Max << endl;
        //| 0.5*(ad+cf+be-bc-de-af) |
    }

    return 0;
}