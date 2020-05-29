#include<iostream>
#include<stack>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;

map<char, int> M;
vector <char> post;
stack <int> S;

int main(){
    int n;
    M['('] = 1;
    M[')'] = 1;
    M['+'] = 2;
    M['-'] = 2;
    M['*'] = 3;
    M['/'] = 3;

    while(cin >> n && n != EOF){
        getchar();
        getchar();
        for(int i = 0; i < n; i++){
            if(i)cout << endl;
            while(!S.empty())S.pop();
            post.clear();
            string term;
            string input;
            while(getline(cin, term)){
                if(term.length() != 0){
                    input += term;
                }else{
                    break;
                }
            }
            //cout << input << endl;
            for(auto c : input){
                if(isdigit(c))post.push_back(c);
                else{
                    if(c == '+' || c == '-' || c == '*' || c == '/'){
                        while(!S.empty() && M[S.top()] >= M[c] ){
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
                        S.pop();
                    }
                }
                // for(int i = 0; i < post.size(); i++){
                //     cout << post[i];
                // }
                // cout << endl;
            }
            
            while(!S.empty()){
                post.push_back(S.top());
                S.pop();
            }
            for(int i = 0; i < post.size(); i++){
                cout << post[i];
            }
            cout << endl;
        }
    }
    return 0;
}
