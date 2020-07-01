#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string s;
    vector<string> ans;
    while(cin >> s && s != "SHOW"){
        if(s == "ADD"){
            string X;
            cin >> X;
            ans.push_back(X);
        }else if(s == "INSERT"){
            string X, N;
            cin >> X >> N;
            ans.insert(find(ans.begin(), ans.end(), N), X);
        }else{
            string X;
            cin >> X;
            ans.erase(find(ans.begin(), ans.end(), X));
        }
    }
    for(auto c : ans){
        cout << c << " ";
    }
    cout << endl;
    

    return 0;
}