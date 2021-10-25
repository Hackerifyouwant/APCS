#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a[105], A[105], B[105];
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        int cntA = 0;
        int cntB = 0;
        for(int i = 0; i < n; i++){
            if(!i % 2)A[cntA++] = a[i];
            else B[cntB++] = a[i];
        }
        for(int i = 0; i < n / 2; i++){
            cout << a[i]
        }
    }

    return 0;
}