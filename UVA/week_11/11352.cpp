#include<iostream>
#include<deque>
#include<map>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

struct pos{
    int x, y, step;
}Start, End;

int king_way[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int knight_way[8][2] = {{1, 2}, {-1, 2}, {-1, -2}, {1, -2}, {2, 1}, {-2, -1}, {-2, 1}, {2, -1}};
deque<pos> Q;
char maps[105][105];

bool check(int boardM, int boardN, int x, int y){
    return (x >= 0 && y >= 0 && x < boardM && y < boardN);
}
bool cnt[105][105];
int chess[1005][1005];

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(chess, -1, sizeof(chess));
        int M, N;
        cin >> M >> N;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cin >> maps[i][j];
                if(maps[i][j] == 'A'){
                    Start.x = i;
                    Start.y = j;
                    Start.step = 0;
                }else if(maps[i][j] == 'B'){
                    End.x = i;
                    End.y = j;
                }  
            }
        }

        

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(maps[i][j] == 'Z'){
                    chess[i][j] = -2;
                    for(int k = 0; k < 8; k++){
                        int nx = i + knight_way[k][0];
                        int ny = j + knight_way[k][1];
                        if(check(M, N, nx, ny)){
                            chess[nx][ny] = -2;
                        }
                    }
                }
            }
        }
        
        chess[Start.x][Start.y] = 0;
        chess[End.x][End.y] = -1;
        Q.clear();
        Q.push_back(Start);
        while(!Q.empty()){
            pos tmp = Q.front();
            Q.pop_front();
            if((tmp.x == End.x) && (tmp.y == End.y)){
                cout << "Minimal possible length of a trip is " << chess[End.x][End.y] << endl;
                break;
            }
            for(int i = 0; i < 8; i++){
                pos nxtmp;
                nxtmp.x = tmp.x + king_way[i][0];
                nxtmp.y = tmp.y + king_way[i][1];
                if(check(M, N, nxtmp.x, nxtmp.y) && chess[nxtmp.x][nxtmp.y] == -1){
                    chess[nxtmp.x][nxtmp.y] = tmp.step + 1;
                    nxtmp.step = tmp.step + 1;
                    Q.push_back(nxtmp);
                }
            }
        }
        //cout << " && " << chess[End.x][End.y] << endl;
        if(chess[End.x][End.y] == -1){
            cout << "King Peter, you can't go now!" << endl;
        }
    }

    return 0;
}

