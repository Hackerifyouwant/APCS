#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;

vector<char> post;
stack<char> S;
stack<int> NS;

int main(){
    string s;
    stringstream ss;
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['%'] = 2;
    
    while(getline(cin, s) && s[0] != EOF){
        post.clear();
        while(!S.empty())S.pop();
        ss.clear();
        ss << s;
        char c;
        while(ss >> c){
            if(isdigit(c)){
                post.push_back(c);
            }else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
                while(!S.empty() && S.top() != '(' && mp[S.top()] >= mp[c]){
                    post.push_back(S.top());
                    S.pop();
                }
                S.push(c);
            }else if(c == '('){
                S.push(c);
            }else if(c == ')'){
                while(!S.empty() && S.top() != '('){
                    post.push_back(S.top());
                    S.pop();
                }
                if(!S.empty() && S.top() == '(')S.pop();
            }
        }
        while(!S.empty()){
            post.push_back(S.top());
            S.pop();
        }
        while(!NS.empty())NS.pop();
        for(auto c : post){
            //cout << c << " ";
            if(isdigit(c)){
                NS.push(int(c - '0'));
            }else{
                int a = NS.top();
                NS.pop();
                int b = NS.top();
                NS.pop();
                int x;
                if(c == '+'){
                    x = b + a;
                }else if(c == '-'){
                    x = b - a;
                }else if(c == '*'){
                    x = b * a;
                }else if(c == '/'){
                    x = b / a;
                }else if(c == '%'){
                    x = b % a;
                }
                //cout << x << endl;
                NS.push(x);
            }
        }
        int ans = NS.top();
        NS.pop();
        cout << ans << endl;
    }

    return 0;
}