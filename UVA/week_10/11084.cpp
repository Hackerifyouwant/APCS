#include<iostream>
#include<algorithm>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;


string s;
vector<int> num;
int d;

int solve(){
    sort(num.begin(), num.end());
    
    int n = num.size();
    int ret = 0;
    do{
        ll v = 0;
        for (int i = 0; i < n; ++i) {
            v = v * 10 + num[i];
        }
        if (v % d == 0)++ret;
    }while(next_permutation(num.begin(), num.end()));

  return ret;

}

int main(){
    int T;
    cin >> T;
    while(T--){ 
        cin >> s >> d;
        num.clear();
        for(int i = 0; i < s.length(); i++){
            num.push_back(s[i] - '0');
        }
        cout << solve() << endl;
    }
    return 0;
}