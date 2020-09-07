#include<iostream>
#include<sstream>
#include<set>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

int n;
multiset<int> M;
multiset<int>::iterator itr;
vector<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n){
        if(n == 0)break;
        else if(n == -2 && !M.empty()){
            itr = M.end();
            itr--;
            //cout << " ** " << *(itr) << endl;
            ans.push_back(*itr);
            M.erase(itr);
        }else if(n == -1 && !M.empty()){
            //cout << " && "<< *(M.begin()) << endl;
            ans.push_back(*(M.begin()));
            M.erase(M.begin());
        }else if(n != -1 && n != -2 && n){
            M.insert(n);
        }
    }
    for(auto c : ans){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}