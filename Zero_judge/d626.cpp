#include<iostream>
#include<queue>

#define ll long long
#define endl '\n'

using namespace std;
struct pos{
    int x, y;
}start;
bool used[105][105];
int way[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    int n;
    string map[105];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    int a, b;
    cin >> a >> b;
    start.x = a;
    start.y = b;
    map[start.x][start.y] = '+';
    queue<pos> Q;
    Q.push(start);
    while(!Q.empty()){
        pos tmp = Q.front();
        Q.pop();
        used[tmp.x][tmp.y] = 1;
        for(int i = 0; i < 4; i++){
            pos nxtmp = tmp;
            nxtmp.x += way[i][0];
            nxtmp.y += way[i][1];
            if(used[nxtmp.x][nxtmp.y] == 0 && map[nxtmp.x][nxtmp.y] == '-'){
                map[nxtmp.x][nxtmp.y] = '+';
                Q.push(nxtmp);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << map[i] << endl;
    }


    return 0;
}