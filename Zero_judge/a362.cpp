#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

struct S{
    int h, w, idx;
}arr[10005];

bool cmp(S l, S r){
    if(l.h == r.h && l.w == r.w)return l.idx < r.idx;
    else if(l.h == r.h)return l.w < r.w;
    return l.h < r.h;
}

int main(){
    int n;
    while(cin >> n){
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++){
            cin >> arr[i].h >> arr[i].w;
            arr[i].idx = i;
        }
        sort(arr, arr + n, cmp);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(arr[i].idx - i);
        }
        cout << ans << endl;
        
    }
    return 0;
}