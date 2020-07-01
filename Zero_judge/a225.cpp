#include<iostream>
#include<sstream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

stringstream ss;

bool cmp(string l, string r){
    if(l[l.size() - 1] == r[r.size() - 1]){
        int al, ar;
        ss.clear();
        ss << l;
        ss >> al;
        ss.clear();
        ss << r;
        ss >> ar;
        
        return al > ar;
    }
    return l[l.size() - 1] < r[r.size() - 1];
}

int main(){
    int n;
    while(cin >> n){
        string arr[1005];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n, cmp);
        for(auto c : arr){
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}