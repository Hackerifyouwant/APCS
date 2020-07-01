#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int a, b, c;
    bool chk = 0;
    cin >> a >> b >> c;
    if(a != 0)a = 1;
    if(b != 0)b = 1;
    if(c != 0)c = 1;
    if((a & b) == c){
        chk = 1;
        cout << "AND" << endl;
    }
    if((a | b) == c){
        chk = 1;
        cout << "OR" << endl;
    }
    if((a ^ b) == c){
        chk = 1;
        cout << "XOR" << endl;
    }
    if(chk == 0){
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}