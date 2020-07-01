#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int n, m, x, y, dis, cost;
char square[105][1005];
        

void dfs(int startx, int starty){
    if(startx < 0 || startx >= n)return ;
    if(starty < 0 || starty >= m)return ;
    square[startx][starty] = '*';

    if(square[startx][starty + 1] == '.'){ 
        dis++;
        dfs(startx, starty + 1);
    }else return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cost = 0;
        cin >> n >> m >> x >> y;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> square[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(square[i][j] == '.'){
                    dis = 1;
                    dfs(i, j);
                    if(dis % 2 == 0){
                        if(dis * x > (dis / 2) * y){
                            cost += (dis / 2) * y;
                        }else{
                            cost += dis * x;
                        }
                    }else{
                        if(dis * x > (dis / 2) * y + x){
                            cost += (dis / 2) * y + x;
                        }else{
                            cost += dis * x;
                        }
                    }
                }
            }
        }
        cout << cost << endl;
    }

    return 0;
}