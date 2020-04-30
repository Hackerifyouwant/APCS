#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int front = 0;
        int second = 0;
        front = int(s[0] - 'A')*pow(26,2) + int(s[1] - 'A')*pow(26,1) + int(s[2] - 'A')*pow(26,0);
        second = int(s[4] - '0')*pow(10,3) + int(s[5] - '0')*pow(10,2) + int(s[6] - '0')*pow(10,1) + int(s[7] - '0')*pow(10,0);
        if(abs(front - second) <= 100)cout << "nice" <<endl;
        else cout << "not nice" << endl;
    }

    return 0;
}