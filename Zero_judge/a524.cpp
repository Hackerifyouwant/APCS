// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<set>

// #define ll long long
// #define endl '\n'

// using namespace std;
    
// set<vector<int> > ans;
// vector<int> path;
// vector<vector<int> > Ans;
// bool used[10];

// void dfs(int level, int target){
//     if(level == target){
//         ans.insert(path);
//         path.pop_back();
//         return;
//     }
//     for(int i = 1; i <= target; i++){
//         if(!used[i]){
//             used[i] = 1;
//             path.push_back(i);
//             dfs(level + 1, target);
//             //path.pop_back();
//             used[i] = 0;
//         }
//     }
//     path.pop_back();
//     return;
// }

// int main(){
//     int n;
//     while(cin >> n){
//         cout << 1 ;
//         ans.clear();
//         path.clear();
//         memset(used, 0, sizeof(used));
//         for(auto c : Ans){
//             c.clear();
//         }
//         Ans.clear();
//         dfs(0, n);
//         for(auto c : ans){
//             Ans.push_back(c);
//         }
//         reverse(Ans.begin(), Ans.end());
//         for(auto c : Ans){
//             for(auto s : c){
//                 cout << s;
//             }
//             cout << endl;
//         }
//         cout << 1 ;
//     }
        

//     return 0;
// }
#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;
    
int main(){
    ll n;
    while(cin >> n){
        string s = "";
        for(int i = n; i >= 1; i--){
            s += char(i + '0');
        }
        cout << s << endl;
        while(prev_permutation(s.begin(), s.end())){
            cout << s << endl;
        }
        
    }

    return 0;
}