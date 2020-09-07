#include<iostream>
#include<stack>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();
    while(n--){
        string s;
        stack<char> ST;
        getline(cin, s);
        if(s == ""){
            cout << "Yes" << endl;
            continue;
        }bool chk = 1;
        for(auto c : s){
            if(c == '(' || c == '['){
                ST.push(c);
            }else if(c == ')'){
                if(ST.empty()){
                    chk = 0;
                    break;
                }
                int a = ST.top();
                if(a == '(')ST.pop();
                else{
                    chk = 0;
                    break;
                }
            }else if(c == ']'){
                if(ST.empty()){
                    chk = 0;
                    break;
                }
                int a = ST.top();
                if(a == '[')ST.pop();
                else{
                    chk = 0;
                    break;
                }
            }
        }
        if(!ST.empty())chk = 0;

        if(chk == 0)cout << "No" << endl;
        else cout << "Yes" << endl;

    }
    return 0;
}