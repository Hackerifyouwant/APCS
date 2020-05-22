#include<iostream>
#include<stack>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        string s;
        stack<char> S;
        bool check = true;
        while(!S.empty())S.pop();
        getline(cin, s);
        //cout << "&&" << s << endl;
        for(auto c : s){
            if(c == '(' || c == '[')S.push(c);
            else{
                if(S.empty()){
                    check = false;
                    break;
                }else if(c == ')'){
                    if(S.top() == '(')S.pop();
                    else{
                        check = false;
                        break;
                    }    
                }else if(c == ']'){
                    if(S.top() == '[')S.pop();
                    else{
                        check = false;
                        break;
                    }
                }
            }
        }
        if(!S.empty() || check == false)cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}