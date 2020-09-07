#include<iostream>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;


int m, n;
bool used[105][105];
string map[105];

int way[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void dfs(int x, int y){
    if(x < 0 || x >= m)return ;
    if(y < 0 || y >= n)return ;

    used[x][y] = 1;
    for(int i = 0; i < 8; i++){
        int nx = x + way[i][0];
        int ny = y + way[i][1];
        if(used[nx][ny] == 0 && map[nx][ny] == '@'){
            dfs(nx, ny);
        }
    }
}

int main(){
    while(cin >> m >> n){
        if(m == 0 && n == 0)break;
        memset(used, 0, sizeof(used));
        for(int i = 0;i < m; i++){
            cin >> map[i];
        }
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(used[i][j] == 0 && map[i][j] == '@'){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << endl;
    }



    return 0;
}