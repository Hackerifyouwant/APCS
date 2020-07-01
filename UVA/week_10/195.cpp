#include<iostream>
#include<set>

#define ll long long
#define endl '\n'

using namespace std;

set<string> s;

int main(){
    int n;
    cin >> n;
    while(n--){
        s.clear();
        string S;
        cin >> S;
        s.insert(S);
        while(next_permutation(S.begin(), S.end())){
            s.insert(S);
        }
        for(auto c : s){
            cout << c << endl;
        }
    }


    return 0;
}

