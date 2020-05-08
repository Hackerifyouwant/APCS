#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

char transfer(char c){
    if(c <= 'Z' && c >= 'A'){
        c += 'a' - 'A';
    }
    return c;
}

int main(){
    int N;
    cin >> N;
    int way[8][2] = {{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{1,-1},{-1,1},{1,1}};
    int index;
    for(int i = 0; i < N; i++){
        int m, n;
        cin >> m >> n;
        char map[105][105];
        for(int j = 0; j < m; j++){
            for(int l = 0; l < n; l++){
                cin >> map[j][l];
                map[j][l] = transfer(map[j][l]);
            }
        }
        int k;
        cin >> k;
        string search;
        bool ans = 0;
        for(int j = 0; j < k; j++){
            cin >> search;
            for(int l = 0; l < search.size(); l++){
                search[l] = transfer(search[l]);
            }
            //search[search.size()] = '\0';
            ans = 0;
            for(int l = 0; l < m && ans ==0; l++){
                for(int f = 0; f < n && ans ==0; f++){
                    for(int y = 0; y < 8 && ans ==0; y++){
                        int nx = l;
                        int ny = f;
                        index = 0;
                        while(search[index] == map[nx][ny]){
                            nx += way[y][0];
                            ny += way[y][1];
                            index++;
                            //cout << "&&"  << nx + 1 << " " << ny + 1 << " " << map[nx][ny] << " " << search[index] << endl;
                            if(search[index] == '\0'){
                                cout << l + 1 << " " << f + 1 << endl;
                                ans = 1;
                                break;
                            }
                            if(nx < 0 || ny < 0 || nx >= m || ny >= n){
                                //cout << "@@" << endl;
                                break;
                            } 
                        }
                    }
                }
            }
        }
        if(i != N - 1)cout << endl;
    }
    return 0;
}