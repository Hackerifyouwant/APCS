#include<iostream>
#include<sstream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string s;
    vector <int> used;
    int pri[40005];
    while(getline(cin, s)){
        int index = 1;
        used.clear();
        memset(pri, 0, sizeof(pri));
        if(s == "0")break;
        stringstream sin(s);
        int p, e, value = 1;
        while (sin >> p >> e)
            value *= pow(p, e);
        value--;
        for(int i = 2;i <= 32767 && value > 1; i++){
            if(value % i == 0){
                used.push_back(i);
            }
            while(value % i == 0){
                value /= i;
                pri[i]++;
            }
        }
        for(int i = used.size() - 1; i >= 0; i--){
            if(i == 0)cout << used[i]  << " " << pri[used[i]];
            else cout << used[i]  << " " << pri[used[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}