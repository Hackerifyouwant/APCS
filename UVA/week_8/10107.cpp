#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    vector<int> V;
    while(cin >> n){
        if(V.empty())V.push_back(n);
        //sort(V.begin(), V.end());
        else{
            V.insert(lower_bound(V.begin(), V.end(), n), n);
        }
        if(V.size() % 2 == 0){
            cout << (V[V.size() / 2 - 1] + V[V.size() / 2]) / 2 << endl;
        }else cout << V[(V.size() + 1) / 2 - 1] << endl;
    }
    return 0;
}