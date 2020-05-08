#include<iostream>
#include<cmath>
#include<iomanip>

#define pi acos(-1)
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    double R, N;
    while(cin >> R >> N){
        double theta = (pi / 2) - (pi / N);
        double r, E, I;
        if(N <= 2){
            r = R / N;
            E = 0;
        }else{
            r = R / (1 + 1 / cos(theta));
            E = (R - r)*(R - r) * sin(2 * pi / N) * N / 2;
            E -= r * r * pi * (theta * 2 * N / pi / 2);
        }
        I = R * R * pi - E - r * r * pi * N;
        cout << fixed << setprecision(10) << r << endl;
        cout << fixed << setprecision(10) << E << endl;   
        cout << fixed << setprecision(10) << I << endl;   
        
    }
    
    return 0;
}