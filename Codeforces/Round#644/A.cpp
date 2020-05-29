#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        int short_edge, long_edge;
        if(a >= b){
            long_edge = a;
            short_edge = b;
        }else{
            long_edge = b;
            short_edge = a;    
        }
        if(short_edge + short_edge >= long_edge){
            cout << 4 * short_edge * short_edge << endl;
        }else{
            cout << long_edge * long_edge << endl;
        }
    }


    return 0;
}