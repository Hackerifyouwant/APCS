#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;
char transfer(string s){
    if(s == "0 1 0 1")return 'A';
    if(s == "0 1 1 1")return 'B';
    if(s == "0 0 1 0")return 'C';
    if(s == "1 1 0 1")return 'D';
    if(s == "1 0 0 0")return 'E';
    if(s == "1 1 0 0")return 'F';
}

int main(){
    unsigned ll N;
    while(cin >> N && N != EOF){
        string s;
        getchar();
        for(unsigned ll i = 0; i < N; i++){
            getline(cin, s);
            //cout << s << endl;
            cout << transfer(s);
        }
        cout << endl;
    }
    return 0;
}