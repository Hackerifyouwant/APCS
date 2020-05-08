#include<iostream>
#include<list>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string s;
    while(cin >> s){
        if(s[0] == EOF)return 0;
        list<char> ans;
        list<char>::iterator itr;
        itr = ans.begin();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                itr = ans.begin();
            }else if(s[i] == ']'){
                itr = ans.end();
            }else{
                ans.insert(itr, s[i]);
            }
        }
        for(itr = ans.begin(); itr != ans.end(); itr++){
            cout << *itr;
        }
        cout << endl;
    }
    
}