#include<iostream>
#include<cmath>
#include<iomanip>

#define ll long long
#define endl '\n'

using namespace std;


int n, seq[1005], min_seq[1005];
double dis[1005][1005];
double Min;
bool vis[1005];

struct pair{
    int x, y;
    double calc(pair& p){
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
}position[1005];



void dfs(int prev, int count, double len){
    if(count == n){
        if(Min > len){
            Min = len;
            for (int i = 0; i < n; i++)
                min_seq[i] = seq[i];
        }
        return ;
    }
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            vis[i] = true;
            seq[count] = i;
            dfs(i, count + 1, len + dis[prev][i]);
            vis[i] = false;
        }
    }
}

int main(){
    int cnt = 1;
    while(cin >> n && n != 0){
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            position[i].x = x;
            position[i].y = y;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                dis[i][j] = dis[j][i] = position[i].calc(position[j]);
            }
        }
        Min = 1e9;
        for(int i = 0; i < n; i++){
            seq[0] = i;
            vis[i] = true;
            dfs(i, 1, 0);
            vis[i] = false;
        }
        cout << "**********************************************************" << endl;
        cout << "Network #" << cnt++ << endl;
        //cout << n << endl;
        for(int i = 0; i < n - 1; i++){
            cout << fixed << setprecision(2) << "Cable requirement to connect (" << position[min_seq[i]].x << "," << position[min_seq[i]].y << ") to (" << position[min_seq[i + 1]].x << "," << position[min_seq[i + 1]].y << ") is " << dis[min_seq[i]][min_seq[i + 1]] + 16 << " feet." << endl;
        }
        cout << fixed << setprecision(2) << "Number of feet of cable required is " << Min + 16 * (n - 1) << "." << endl;
    }

    return 0;
}