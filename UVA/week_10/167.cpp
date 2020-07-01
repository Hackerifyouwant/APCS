// #include<iostream>

// #define ll long long
// #define endl '\n'

// using namespace std;

// int map[10][10];
// int vis[10][10];
// bool check = 0;
// int max_sum;

// void change(int x, int y, int dx, int dy){
//     int id = x + 1;
//     //id = 下一行
//     while ( x < 8 && x >= 0 && y < 8 && y >= 0 ) {
// 		//檢查邊界
//         if (vis[x][y] == 0) vis[x][y] = id;
// 		//檢查是否走過，未走過的話填上下一行的index
//         else if (vis[x][y] == id) vis[x][y] = 0; 
//         //走過的話，代表此格無效，填0
// 		x += dx; y += dy;
// 	}
// }

// void dfs(int x, int v){
//     if(x == 8){
//         //當放滿了八個皇后，比較最大值
//         if(max_sum < v)max_sum = v;
//         return;
//     }

    
//     for(int i = 0; i < 8; i++){
//         //從第一格橫向走到第八格
//         if(vis[x][i] == 0){
//             change(x, i, 1, 0);//往下走
// 			change(x, i, 1, 1);//往右下走
// 			change(x, i, 1, -1);//往左下走
//             dfs(x + 1, v + map[x][i]);//往下一行放下一個皇后
//             //回朔
//             change(x, i, 1, 0);//往下走
// 			change(x, i, 1, 1);//往右下走
// 			change(x, i, 1, -1);//往左下走
			
//         }
//     }
// }

// int main(){
//     int k;
//     cin >> k;
//     while(k--){
//         //建立地圖，還有初始化
//         for(int i = 0; i < 8; i++){
//             for(int j = 0; j < 8; j++){
//                 cin >> map[i][j];
//                 vis[i][j] = 0;
//             }
//         }
//         max_sum = 0;
//         dfs(0, 0);
//         printf("%5d\n",max_sum);

//     }


//     return 0;
// }
#include<iostream>
#include<cstring>

#define ll long long
#define endl '\n'

using namespace std;

int s[8], m[8][8], re;

void qn(int step){
    if(step < 8){
        for(int i = 0; i < 8; i++){
            //往右橫掃
            for(int j = 0; j < 8; j++){
                //檢查跟過去的皇后有沒有衝突
                if ((s[j] == i) || ((s[j] - i) == (j - step)) || ((s[j] - i) == (step - j))) break;//有一個衝突就不用再檢查  
                //當在同一直線上時，還有往左差距跟往上差距一樣時，等於是說站在等角線，所以不合法
                if (j == (step - 1)) {  //每一行都檢查，沒有衝突才加入 
                    //cout << " %% "<< s[j] << " " << i << " " << j << " " <<  step << endl; 
                    s[step] = i;
                    qn(step + 1);
                    //進入下一行 
                }
            }
        }
    }else {//八列都填滿，計算加總和 
        int sum = 0;
        for(int i = 0; i < 8; i++){
            sum += m[i][s[i]];        
        }    
        if (re < sum) re = sum;    
    }     
}

int main(){
    int n;
    cin >> n;
    for(int k = 0; k < n; k++){
        re = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> m[i][j];
            }
        }
        for(int i = 0; i < 8; i++){
            s[0] = i;
            qn(1);
        }
        cout.width(5);
        cout << re << endl;
    }



    return 0;
}