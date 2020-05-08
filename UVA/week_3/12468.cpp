#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        if(a == -1 && b == -1)break;
        if(a > b)swap(a, b);
        int min1 = b - a;
        int min2 = (99 - b) + a + 1;
        int min_ = min(min1, min2);
        cout << min_ << endl;
    }

    return 0;
}