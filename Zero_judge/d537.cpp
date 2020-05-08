#include<iostream>
#include<queue>

#define ll long long
#define endl '\n'

using namespace std;

struct N{
    char color[3];
    int index;
    int x;
    int y;
};
struct N coor[3];
int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// char combination(char a, char b, ){
//     if(a == 'R' && b == 'B' && )
// }

void Flood_Fill(){
    queue< struct N > travel;
    for(int i = 0;i < 3; i++){
        travel.push(coor[i]);
    }
    while(!travel.empty()){
        struct N u = travel.front();
        travel.pop();
        for(int j = 0; j < 4; j++){
            struct N Nxy;
            Nxy.x = u.x + way[j][0];
            Nxy.y = u.y + way[j][1];
            Nxy.color[Nxy.index++] = u.color[u.index++];
            travel.push(Nxy);
        }
        if() 
    }
}

int main(){
    int N;
    cin >> N;
    int map[105][105];
    char search_color;
    for(int i = 0; i < 3; i++){
        cin >> coor[i].color >> coor[i].x >> coor[i].y;
    }
    cin >> search_color;
    Flood_Fill();

    return 0;
}