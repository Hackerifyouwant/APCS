#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, a[10005], b[10005];
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        sort(b, b + n);
        for(int i = 0; i < k; i++){
            if(a[i] > b[n - i - 1])break;
            swap(a[i], b[n - i - 1]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        cout << sum << endl;

    }

    return 0;
}