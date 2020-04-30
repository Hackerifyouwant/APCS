#include<iostream>
#include<vector>
#include<string>
#include<cctype>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    char c;
    string s;
    vector<string> v;
    while(getline(cin, s) && s[0] != '0'){
        for(int i = 0; i < s.size(); i++){
            string test;
            if(isalpha(s[i])){
                cout << s[i];
                test += s[i];
            }else if(isdigit(s[i])){
                cout << int(s[i]- '0');
                //cout << v[int(s[i]- '0')];
            }else{
                if(s[i] == ' '){
                    v.insert(v.begin(), test);
                    cout << test << " ";
                    test = "";
                }else{
                    cout << s[i];
                }
            }
        }
        cout << endl;
    }
    return 0;
}