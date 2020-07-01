#include<iostream>
#include<sstream>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int T;
    cin >> T;
    stringstream ss;
    string S;
    string code;
    map<string, char> r;
    r[".-"] = 'A', r["-..."] = 'B', r["-.-."] = 'C';
    r["-.."] = 'D', r["."] = 'E', r["..-."] = 'F';
    r["--."] = 'G', r["...."] = 'H', r[".."] = 'I';
    r[".---"] = 'J', r["-.-"] = 'K', r[".-.."] = 'L';
    r["--"] = 'M', r["-."] = 'N', r["---"] = 'O';
    r[".--."] = 'P', r["--.-"] = 'Q', r[".-."] = 'R';
    r["..."] = 'S', r["-"] = 'T', r["..-"] = 'U';
    r["...-"] = 'V', r[".--"] = 'W', r["-..-"] = 'X';
    r["-.--"] = 'Y', r["--.."] = 'Z', r["-----"] = '0';
    r[".----"] = '1', r["..---"] = '2', r["...--"] = '3';
    r["....-"] = '4', r["....."] = '5', r["-...."] = '6';
    r["--..."] = '7', r["---.."] = '8', r["----."] = '9';
    r[".-.-.-"] = '.', r["--..--"] = ',', r["..--.."] = '?';
    r[".----."] = '\'', r["-.-.--"] = '!', r["-..-."] = '/';
    r["-.--."] = '(', r["-.--.-"] = ')', r[".-..."] = '&';
    r["---..."] = ':', r["-.-.-."] = ';', r["-...-"] = '=';
    r[".-.-."] = '+', r["-....-"] = '-', r["..--.-"] = '_';
    r[".-..-."] = '\"', r[".--.-."] = '@';
    
    getchar();
    for(int i = 0; i < T; i++){
        ss.clear();
        S.clear();
        getline(cin, S);
        if(i != 0)cout << endl;
        cout << "Message #" << i + 1 << endl;
        int cnt = 0;
        
        for(auto c : S){
            if(isspace(c)){
                if(code.empty())cout << ' ';
                else {
                    cout << r[code];
                    //cout << code << " ";
                    code.clear();
                }
            }else{
                code += c;
            }
        }
        if(!code.empty())cout << r[code];
        code.clear();
        cout << endl;
    }
    return 0;
}




