#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    int prime = 0;
    while(cin >> n){
        if(n == 0)break;
        int ans = n;
        prime = 0;
        for(int i = 2; i < 1000000 && n > 1; i++){
            //cout << "**" << n << endl;
            if(n % i == 0){
                n /= i;
                prime++;
            }
            while(n % i == 0){
                n /= i;
            }
        } 
        cout << ans << " : " << prime << endl;
    }
    return 0;
}