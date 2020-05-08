// #include<iostream>

// #define ll long long
// #define endl '\n'

// using namespace std;
// int count_ = 0;
// int N, M;
// char map[15][15];
// char ans[15][15];
// bool check = 0;
// int way[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// void dfs(int x, int y){
//     ans[x][y] = '0';
//     for(int i = 0; i < 4; i++){
//         int nx = x + way[i][0];
//         int ny = y + way[i][1];
//         if(nx >= 0 && ny >=0 && nx < N && ny < M){
//             if(ans[nx][ny] == '?' && map[nx][ny] == '0'){
//                 dfs(nx, ny);
//                 count_ ++;
//                 break;
//             }           
//         }
//     }
//     for(int i = 0; i < 4; i++){
//         int nx = x + way[i][0];
//         int ny = y + way[i][1];
//         if(nx >= 0 && ny >= 0 && nx < N && ny < M){
//             ans[nx][ny] = map[nx][ny];           
//         }
//     }
// }

// int main(){
//     while(cin >> N >> M){
//         count_ = 0;
//         if(N == 0 && M == 0)break;
//         int x_ini, y_ini;
//         cin >> x_ini >> y_ini;
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < M; j++){
//                 cin >> map[i][j];
//                 ans[i][j] = '?';
//             }
//         }
//         dfs(x_ini - 1, y_ini - 1);
//         cout << endl;
//         for(int i = 0 ; i < M; i++){
//             cout << "|---";
//         }
//         cout << "|" << endl;
//         for(int i = 0; i < N; i++){
//             cout << "| ";
//             for(int j = 0; j < M; j++){
//                 if(j == M - 1)cout << ans[i][j] << " |";
//                 else cout << ans[i][j] << " | ";
//             }
//             cout << endl;
//             for(int i = 0 ; i < M; i++){
//                 cout << "|---";
//             }
//             cout << "|" << endl;    
//         }
//         cout << endl;
//         cout << "NUMBER OF MOVEMENTS: " << count_ << endl;
//     }
//     return 0;
// }
#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;
int count_ = 0;
int N, M;
char map[15][15];
char ans[15][15];
bool check = 0;
int way[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void dfs(int x, int y){
    ans[x][y] = '0';
    check = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + way[i][0];
        int ny = y + way[i][1];
        if(nx >= 0 && ny >=0 && nx < N && ny < M){
            if(ans[nx][ny] == '?' && map[nx][ny] == '0' && check == 0){
                
                dfs(nx, ny);
                check = 1;
                count_ ++;
                //break;
            }
            ans[nx][ny] = map[nx][ny];           
        }
    }
    // for(int i = 0; i < 4; i++){
    //     int nx = x + way[i][0];
    //     int ny = y + way[i][1];
    //     if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                       
    //     }
    // }
}

int main(){
    while(cin >> N >> M){
        count_ = 0;
        if(N == 0 && M == 0)break;
        int x_ini, y_ini;
        cin >> x_ini >> y_ini;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[i][j];
                ans[i][j] = '?';
            }
        }
        dfs(x_ini - 1, y_ini - 1);
        cout << endl;
        for(int i = 0 ; i < M; i++){
            cout << "|---";
        }
        cout << "|" << endl;
        for(int i = 0; i < N; i++){
            cout << "| ";
            for(int j = 0; j < M; j++){
                if(j == M - 1)cout << ans[i][j] << " |";
                else cout << ans[i][j] << " | ";
            }
            cout << endl;
            for(int i = 0 ; i < M; i++){
                cout << "|---";
            }
            cout << "|" << endl;    
        }
        cout << endl;
        cout << "NUMBER OF MOVEMENTS: " << count_ << endl;
    }
    return 0;
}