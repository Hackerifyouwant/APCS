#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string s, t;
    while(cin >> s >> t){
        int sindex = 0;
        for(int i = 0; i < t.length(); i++){
            if(t[i] == s[sindex]){
                sindex++;
                if(sindex == s.length()){
                    break;
                }
            }
        }
        if(sindex == s.length()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}