#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

struct T{
    ll w, f;
}t[100005];

bool cmp(T l, T r){
    return l.w * r.f < r.w * l.f;
}

int main(){
    ll N;
    ll sum = 0;
    cin >> N;
    for(ll i = 0; i < N; i++){
        cin >> t[i].w;
    }
    for(ll i = 0; i < N; i++){
        cin >> t[i].f;
    }
    sort(t, t + N, cmp);
    ll result = 0;
    for(ll i = 0; i < N; i++){
        sum += t[i].w;
        result += sum * t[i + 1].f;
    }
    cout << result << endl;
    return 0;
}