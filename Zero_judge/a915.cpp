#include<iostream>
#include<algorithm>
#include<utility>

#define ll long long
#define endl '\n'

using namespace std;

bool cmp(pair<ll, ll> l, pair<ll, ll> r){
    if(l.first == r.first)return l.second < r.second;
    return l.first < r.first;
}

int main(){
    int n;
    cin >> n;
    pair<ll,ll> pi[10005];
    for(int i = 0; i < n; i++){
        cin >> pi[i].first >> pi[i].second;
    }
    sort(pi, pi + n, cmp);
    for(int i = 0; i < n; i++){
        cout << pi[i].first << " " << pi[i].second << endl;
    }
    return 0;
}