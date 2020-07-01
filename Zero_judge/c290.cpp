#include<iostream>
#include<math.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string x;
    cin >> x;
    int odd = 0, even = 0;
    for(int i = 0; i < x.size(); i++){
        if(i % 2 == 0)odd += int(x[i] - '0');
        else even += int(x[i] - '0');
    }
    cout << abs(odd - even) << endl;

    return 0;
}