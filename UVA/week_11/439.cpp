#include<iostream>
#include<queue>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

struct pos{
    int x;
    int y;
};

int way[8][2] = {{1, 2},{1, -2},{-1, 2},{-1, -2},{2, 1},{2, -1},{-2, 1},{-2, -1}};
int segment[105];
int segment_c;
bool check;

int main(){
    string start, end;
    int map[10][10];
    int ans;
    pos s;
    pos e;
    queue<pos> Q;
    while(cin >> start >> end && start[0] != EOF){
        if(start == end){
            cout << "To get from " << start << " to " << end << " takes " << 0 <<" knight moves." << endl;
            continue;
        }
        check = 0;
        while(!Q.empty())Q.pop();
        memset(segment, 0 , sizeof(segment));
        segment_c = 0;
        
        s.x = int(start[0] - 'a' + 1);
        s.y = int(start[1] - '0');
        e.x = int(end[0] - 'a' + 1);
        e.y = int(end[1] - '0');
        
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                map[i][j] = 0;
            }
        }
        map[e.x - 1][e.y - 1] = 2;
        map[s.x - 1][s.y - 1] = 1;
        pos tmp;
        tmp.x = s.x - 1;
        tmp.y = s.y - 1;
        Q.push(tmp);
        segment[segment_c]++;
        while(!Q.empty() && check == 0){
            if(segment[segment_c] == 0)segment_c++;
            pos tmp;
            tmp = Q.front();
            Q.pop();
            segment[segment_c]--;
            for(int i = 0; i < 8; i++){
                int nx = tmp.x + way[i][0];
                int ny = tmp.y + way[i][1];
                if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8){
                    //cout << segment_c << " " << nx << " " << ny << endl;
                    if(map[nx][ny] == 0){
                        pos t;
                        t.x = nx;
                        t.y = ny;
                        Q.push(t);
                        segment[segment_c + 1]++;
                    }else if(map[nx][ny] == 2){
                        check = 1;
                        break;
                    }
                }
            }
            
        }

        cout << "To get from " << start << " to " << end << " takes " << segment_c + 1 <<" knight moves." << endl;
    }
    return 0;
}

