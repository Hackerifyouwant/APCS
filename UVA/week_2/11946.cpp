#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;
char transfer(char c){
    if(c == '0')return c = 'O';
    if(c == '1')return c = 'I';
    if(c == '2')return c = 'Z';
    if(c == '3')return c = 'E';
    if(c == '4')return c = 'A';
    if(c == '5')return c = 'S';
    if(c == '6')return c = 'G';
    if(c == '7')return c = 'T';
    if(c == '8')return c = 'B';
    if(c == '9')return c = 'P';
}

int main(){
    int T;
    string s;
    cin >> T;
    cin.get();
    for(int i = 0; i < T; i++){
        if(i != 0)cout << endl;
        while(getline(cin, s) && s.size() != 0){
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                if(isdigit(c))cout << transfer(c);
                else cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}