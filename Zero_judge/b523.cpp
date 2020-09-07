#include<iostream>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string s;
    map<string, int> mp;
    while(getline(cin, s)){
        if(mp.find(s) != mp.end()){
            cout << "YES" << endl;
        }else{
            mp[s] = 1;
            cout << "NO" << endl;
        }
    }

    return 0;
}