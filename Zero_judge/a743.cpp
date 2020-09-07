// #include<iostream>
// #include<sstream>
// #include<map>
// #include<set>

// #define ll long long
// #define endl '\n'

// using namespace std;

// pair<string, int> country;
// stringstream ss;
// string s, a;
// int n;

// bool cmp(pair<string, int> l, pair<string, int> r){
//     return l.first[0] > r.first[0];
// }

// int main(){
//     while(cin >> n){
//         getchar();
//         for(int i = 0; i < n; i++){
//             s = "";
//             a = "";
//             getline(cin, s);
//             ss.clear();
//             ss << s;
//             ss >> a;
//             country[a]++;
//             while(ss >> a);
//         }
//         sort(country.begin(), country.end(), cmp);
//     }

//     return 0;
// }
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map <string, int> mp;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        stringstream ss(s);
        ss >> s;
        mp[s]++;
    }
    for (auto i: mp) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}