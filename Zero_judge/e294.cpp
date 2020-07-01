#include<iostream>
#include<algorithm>
#include<sstream>
#include<math.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string n;
    stringstream ss;
    
    while(cin >> n && n[0] != EOF){
        ll Min = 0;
        for(ll i = 0; i < n.size(); i++){
            if(int(n[i] - '0') % 2 == 0){
                ll N = 0, a1 = 0, a2 = 0;
                if(n[i] == '0'){
                    ss.clear();
                    ss << n;
                    ss >> N;
                    string s1 = n;
                    
                    s1[i] = '9';
                    ll idx = i - 1;
                    while(idx > 0 && s1[idx] == '1'){
                        s1[idx] = '9';
                        idx--;
                    }
                    s1[idx] -= 2;
                    if (s1[idx] < '0') s1[idx] = '0';

                    for(ll j = i + 1; j < n.size(); j++){
                        s1[j] = '9';
                    }
                    //cout << s1 << endl;
                    ss.clear();
                    ss << s1;
                    ss >> a1;
                    

                    string s2 = n;
                    
                    s2[i] += 1;
                    for(ll j = i + 1; j < n.size(); j++){
                        s2[j] = '1';
                    }

                    ss.clear();
                    ss << s2;
                    ss >> a2;
                    
                    Min = min(abs(N - a1), abs(N - a2));
                }else{
                    ss.clear();
                    ss << n;
                    ss >> N;
                    string s1 = n;
                    
                    if(s1[i] > '0'){
                        s1[i] -= 1;
                        for(ll j = i + 1; j < n.size(); j++){
                            s1[j] = '9';
                        }
                        ss.clear();
                        ss << s1;
                        ss >> a1;
                    }else{
                        a1 = 1e9;
                    }
                    
                    string s2 = n;
                    
                    s2[i] += 1;
                    for(ll j = i + 1; j < n.size(); j++){
                        s2[j] = '1';
                    }

                    ss.clear();
                    ss << s2;
                    ss >> a2;

                    Min = min(abs(N - a1), abs(N - a2));
                }
                //cout << N << " " << a1 << " " << a2 << endl;
                break;
            }
        }
        cout << Min << endl;
    }
    return 0;
}