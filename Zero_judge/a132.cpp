#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int cnt;

string parity(int x){
    string ans;
    while(x > 0){
        ans += char(x % 2 + '0');
        if(x % 2 == 1)cnt++;
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int l;
    while(cin >> l && l != 0){
        cnt = 0;
        string A = parity(l);
        cout << "The parity of " << A << " is " << cnt << " (mod 2)." << endl;
    }



    return 0;
}