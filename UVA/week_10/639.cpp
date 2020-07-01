//We can do it with backtracking. The so-called backtracking is to return a state on dfs when there is more state return, the others are the same.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 5;
 
int n , ans , flag;
char G[MAXN][MAXN];
int vis[MAXN][MAXN]; //Initialize the position of 'X' to -1, others are 0
 
 
int judge(int x, int y) {
    for (int i = x - 1; i >= 0; i--) {
        if (vis[i][y] == 1)//If 1 is not satisfied
            return 0;
        if (vis[i][y] == -1)//If it is 'X' then exit
            break;
    }
    for (int i = y - 1; i >= 0; i--) {
        if (vis[x][i] == 1)
            return 0;
        if (vis[x][i] == -1)
            break;
    }
    return 1;
}
 
 //Backtracking search
 
void dfs(int i, int j, int max) {
    if (max > ans)
        ans = max;
    while (i < n) {
        if (j < n && G[i][j] == '.' && vis[i][j] == 0) {
            flag = judge(i, j);
            if (flag) {
                vis[i][j] = 1;
                dfs(i, j + 1, max + 1);
                vis[i][j] = 0;
            }
        }
        if (j >= n) {
            ++i;
            j = 0;
        }
        else
            ++j;
    }
}
 
 
 

int main() {
    //freopen("input.txt" , "r" , stdin);
    while (cin >> n && n != 0) {
        memset(vis, 0, sizeof (vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> G[i][j];
                if (G[i][j] == 'X') {
                    vis[i][j] = -1; //Initialize vis array
                }
            }
            getchar();
        }
        ans = 0;
        dfs(0, 0, 0); //call function (start searching subtree)
        cout << ans << endl;
    }
    return 0;
}
 
 
 

