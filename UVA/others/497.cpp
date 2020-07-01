#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

#define ll long long
#define endl '\n'

using namespace std;


int main(){
    ll T;
    cin >> T;
    getchar();
    getchar();
    while(T--){
        vector<int> M;
        string s;
        while (getline(cin, s) && s != ""){ 
            stringstream ss(s);
            int missle;

            ss >> missle;
            M.push_back(missle);
        }

        vector<int> LIS(M.size(), 1);
        vector<int> path(M.size(), -1);
        LIS[0] = 1;      
        for (ll i = 1; i < M.size(); i++){
            for (ll j = 0; j < i; j++){
                int l = 0;
                if(M[j] < M[i]){
                    l = LIS[j] + 1;
                }
                if (l > LIS[i]){
                    LIS[i] = l;
                    path[i] = j;
                }
            }
        }
        

        int i = distance(LIS.begin(),max_element(LIS.begin(), LIS.end()));
        vector<int> print(1, M[i]);
        while (path[i] != -1){
            i = path[i];
            print.insert(print.begin(), M[i]);
        }
        cout << "Max hits: " << print.size() << endl;
        for(auto c : print){
            cout << c << endl;
        }
        if (T)cout << endl;
    }


    return 0;
}