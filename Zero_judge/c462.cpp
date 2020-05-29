#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

vector <int> vec;
bool vis[1000005];
int cnt;
int Max = -1e9;
int k;
    

int transfer(char c){
    if(c >= 'a' && c <= 'z')return 0;
    return 1;
}

void dfs(int start){
    if(start < 0 || start >= vec.size())return;
    vis[start] = 1;
    
    for(int i = start; i < start + k - 1; i++){
        if(vec[i] != vec[i + 1])return;
    }
    cnt += k;
    if((vec[start] ^ vec[start + k]) == 1 && vis[start + k] == 0){
        dfs(start + k);
    }
    if((vec[start] ^ vec[start - k]) == 1 && vis[start - k] == 0){
        dfs(start - k);
    }
    Max = max(Max, cnt);
    return;
}

int main(){
    string S;
    cin >> k;
    cin >> S;
    for(auto c : S){
        vec.push_back(transfer(c));
    }
    for(int i = 0; i < vec.size(); i++){
        cnt = 0;
        dfs(i);        
    }
    if(Max == -1e9)cout << 0 << endl;
    else cout << Max << endl;

    return 0;        
}