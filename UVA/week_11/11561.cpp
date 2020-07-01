#include<iostream>
#include<deque>
#include<vector>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

struct pos{
    int x, y;
}start;

int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char map[105][105];  
int vis[105][105];
deque<pos> Q;

bool check (int boardH, int boardW, pos T){
    return (T.x >= 0 && T.y >= 0 && T.x < boardH && T.y < boardW);
}

int main(){
    int W, H;
    while(scanf("%d%d", &W, &H) == 2){
        int gold = 0;
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> map[i][j];
            }
        }
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(map[i][j] == 'P'){
                    start.x = i;
                    start.y = j;
                }else if(map[i][j] == 'T'){
                    for(int k = 0; k < 4; k++){
                        pos nxtmp;
                        nxtmp.x = i + way[k][0];
                        nxtmp.y = j + way[k][1];
                        if(check(H, W, nxtmp)){
                            if(vis[nxtmp.x][nxtmp.y] == 0){
                                vis[nxtmp.x][nxtmp.y] = -1;
                            }
                        }
                    }
                }
            }
        }

        if(vis[start.x][start.y] == -1){
            cout << 0 << endl;
            continue;
        }
        Q.clear();
        Q.push_back(start);
        vis[start.x][start.y] = 1;
        while(!Q.empty()){
            pos tmp = Q.front();
            Q.pop_front();
            for(int i = 0; i < 4; i++){
                pos nxtmp = tmp;
                nxtmp.x += way[i][0];
                nxtmp.y += way[i][1];
                //cout << nxtmp.x << " " << nxtmp.y << " " << map[nxtmp.x][nxtmp.y] << " "<< vis[nxtmp.x][nxtmp.y] << endl;
                if(check(H, W, nxtmp) && vis[nxtmp.x][nxtmp.y] != 1 && map[nxtmp.x][nxtmp.y] != '#'){
                    if(vis[nxtmp.x][nxtmp.y] != -1){
                        Q.push_back(nxtmp);
                    }
                    vis[nxtmp.x][nxtmp.y] = 1;
                    if(map[nxtmp.x][nxtmp.y] == 'G')gold++;
                }
            }
        }


        cout << gold << endl;
    }
    return 0; 
}

