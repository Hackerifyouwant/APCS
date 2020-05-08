#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int G;
    
    while(cin >> G){
        if(G == 0)return 0;
        string s; 
        cin >> s;
        vector<char> v(s.begin(), s.end());
        G = v.size() / G;
        for(int i = 0; i < v.size(); i += G){
            reverse(v.begin() + i, v.begin() + i + G);
        }
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}