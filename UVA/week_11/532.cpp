#include<iostream>
#include<queue>

#define ll long long
#define endl '\n'

using namespace std;

struct pos{
    int x,y,z;
    int step;
};

char maze[105][105][105];
int vis[105][105][105];
int way[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
queue<pos> Q;
int L, R, C;

bool check(pos D){
    if(D.x >= 0 && D.y >= 0 && D.z >= 0 && D.x < L && D.y < R && D.z < C)return true;
    else return false;
}
    
int main(){
    while(cin >> L >> R >> C){
        if(L == 0 && R == 0 && C == 0)break;
        pos start;
        pos end;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    cin >> maze[i][j][k];
                    if(maze[i][j][k] == 'S'){
                        start.x = i;
                        start.y = j;
                        start.z = k;
                        vis[i][j][k] = 1;
                        start.step = 0;
                    }else if(maze[i][j][k] == 'E'){
                        end.x = i;
                        end.y = j;
                        end.z = k;
                        vis[i][j][k] = 2;
                    }else if(maze[i][j][k] == '.'){
                        vis[i][j][k] = 0;
                    }else if(maze[i][j][k] == '#'){
                        vis[i][j][k] = 1;
                    }
                }
            }
            getchar();
        }

        while(!Q.empty())Q.pop();
        Q.push(start);
        int ans = -1;
        while(!Q.empty()){
            pos tmp;
            tmp = Q.front();
            Q.pop();
            for(int i = 0; i < 6; i++){
                pos nxtmp;
                nxtmp.x = tmp.x + way[i][0];
                nxtmp.y = tmp.y + way[i][1];
                nxtmp.z = tmp.z + way[i][2];
                nxtmp.step = tmp.step;
                if(check(nxtmp)){
                    if(vis[nxtmp.x][nxtmp.y][nxtmp.z] == 0){
                        vis[nxtmp.x][nxtmp.y][nxtmp.z] = 1;
                        nxtmp.step++;
                        Q.push(nxtmp);
                    }else if(vis[nxtmp.x][nxtmp.y][nxtmp.z] == 2){
                        ans = nxtmp.step + 1;
                        while(!Q.empty())Q.pop();
                        break;
                    }
                }
            }
        }
        if(ans == -1)cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    
        
    }
    //cout << endl;
    return 0;
}



