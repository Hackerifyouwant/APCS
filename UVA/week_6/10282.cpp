#include<iostream>
#include<map>
#include<string>
#include<sstream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    map<string, string> dictionary;
    string s;
    
    while(getline(cin, s) && s != ""){
        stringstream ss;
        ss << s;
        string key, value;
        ss >>  value >> key;
        dictionary[key] = value;
    }
    string input;
    while(getline(cin, input)){
        if(dictionary.find(input) == dictionary.end()){
            cout << "eh" << endl;
        }else{
            cout << dictionary[input] << endl;
        }
    }
    return 0;
}