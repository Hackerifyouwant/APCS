#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int k = 7;
    string s;
    while(cin >> s){
        for(int i = 0; i < s.size(); i++){
            s[i] -= k;
        }
        cout << s << endl;
    } 
}