#include<iostream>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

int k, arr[15]; 
int path[15];
bool vis[15];
void f(int level){
    if(level == 6){
        for(int i = 0; i < 5; i++){
            cout << path[i] << " ";
        }
        cout << path[5] << endl;
        return ;
    }
    for(int i = 0; i < k; i++){
        if(vis[i] == 0){
            if(path[level - 1] < arr[i]){
                vis[i] = 1;
                path[level] = arr[i];
                f(level + 1);
                vis[i] = 0;
            }
        }
    }
}

int main(){
    int cnt = 0;
    while(cin >> k && k != 0){
        if(cnt++ != 0)cout << endl;
        for(int i = 0; i < k; i++){
            cin >> arr[i];
            vis[i] = 0;
        }
        f(0);
    }
    return 0;
}