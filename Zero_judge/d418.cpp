#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        string s;
        while(x > 0){
            for(int i = 9; i >= 1; i--){
                if(x % i == 0){
                    s += char(i + '0');
                    x /= i;
                    cout << s << endl;
                }
            }
        }       
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}