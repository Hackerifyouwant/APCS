#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>

#define ll long long
#define endl '\n'
#define maxn 105
#define eps 1e-10

using namespace std;

int dcmp(double x){
    if(fabs(x) < eps)return 0;
    return x < 0 ? -1 : 1;
}

struct Point{
    double x, y;
    Point(){};
    Point(double x, double y):x(x), y(y){};
    bool operator==(const Point &rhs)const{
        return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
    }
    bool operator<(const Point &rhs)const{
        return x < rhs.x || (dcmp(x - rhs.x) == 0 && y < rhs.y);
    }
}P[maxn];

typedef Point Vector;
Vector operator-(Point A, Point B){
    return Vector(A.x - B.x, A.y - B.y);
}

double cross(Vector A, Vector B){
    return A.x * B.y - A.y * B.x;
}

bool InLine(Point P, Point A, Point B){
    return dcmp(cross(P - A, A - B)) == 0;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> P[j].x >> P[j].y;
        }
        sort(P, P + N);
        N = unique(P, P + N) - P; 
        //cout << N + P << endl;
        if(N == 1){
            cout << "Data set #" << i + 1 << " contains a single gnu." << endl;
            continue;        
        }
        int ans = 0;
        for(int j = 0; j < N; j++){
            for(int n = j + 1; n < N; n++){
                int num = 0;
                for(int k = 0; k < N; k++){
                    if(InLine(P[k], P[j], P[n])) num++;
                }
                ans = max(ans, num);
            }
        }
        cout << "Data set #" << i + 1 << " contains " << N << " gnus, out of which a maximum of " << ans << " are aligned."<< endl;
    }
    return 0;
}
