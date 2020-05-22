#include<iostream>
#include<cmath>
#include<iomanip>

#define ll long long
#define endl '\n'
#define equation (c / sqrt(x * x - mid * mid) + c / sqrt(y * y - mid * mid))

using namespace std;

int main(){
    double x, y, c;
    while(cin >> x >> y >> c){
        double l = 0.0, r = x;
        if(r > y){
            r = y;
        }
        double mid = (r + l) * 0.5;
        while(r - l > 1e-5){
            mid = (r + l) * 0.5;
            if(equation < 1.0){
                l = mid;
            }else{
                r = mid;
            }
        
        }
        cout << fixed << setprecision(3) << mid << endl;
    }

    return 0;
}