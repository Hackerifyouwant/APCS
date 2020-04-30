#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;
int transfer(char c){
    if(c == 'W') return 64;
    if(c == 'H') return 32;
    if(c == 'Q') return 16;
    if(c == 'E') return 8;
    if(c == 'S') return 4;
    if(c == 'T') return 2;
    if(c == 'X') return 1;
}

int main(){
    string s;
    while(cin >> s){
        if(s == "*")return 0;
        int count = 0;
        int ans = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '/'){
                //cout << count << endl;
                if(count == 64){
                    ans++;    
                }
                count = 0;
            }else{
                count += transfer(s[i]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}