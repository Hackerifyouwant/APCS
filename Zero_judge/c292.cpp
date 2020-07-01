#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int way[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int n;
int inway;
int map[50][50];
bool used[50][50];

void dfs(int startx, int starty, int step, int Way, bool S){
    used[startx][starty] = 1;
    Way %= 4;
    int nx = startx, ny = starty;
    for(int i = 0; i < step; i++){
        nx += way[Way][0];
        ny += way[Way][1];
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && !used[nx][ny]){
            cout << map[nx][ny];
            used[nx][ny] = 1;
        }
    }
    //cout << " && " << nx << " " << ny << " " << step << " " << Way << " " << S << endl;
    if(S == 1)step++;
    S ^= 1;
    Way++;
    if(nx >= 0 && ny >= 0 && nx < n && ny < n)dfs(nx, ny, step, Way, S);
    return ;
}

int main(){
    
    cin >> n >> inway;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    cout << map[n / 2][n / 2];
    dfs(n / 2, n / 2, 1, inway, 0);
    cout << endl;


    return 0;
}