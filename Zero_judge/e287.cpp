// #include<iostream>

// #define ll long long
// #define endl '\n'

// using namespace std;

// struct stat{
//     int Min;
//     int i;
//     int j;
// }A;

// int n, m;

// bool check_(int x, int y){
//     if (x >= 0 && x < n && y >= 0 && y < m) return true;
//     return false;
// }

// bool vis[105][105];
// long long map[105][105];

// int main(){
    
//     cin >> n >> m;
    
//     int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     A.Min = 1e9;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cin >> map[i][j];
//             if(A.Min > map[i][j]){
//                 A.Min = map[i][j];
//                 A.i = i;
//                 A.j = j;
//             }
//         }
//     }
//     int nx = A.i;
//     int ny = A.j;
//     vis[nx][ny] = 1;
//     int sum = A.Min;
//     int min = 1e9;
//     int N = -1;
    
//     while(1){
//         min = 1e9;
//         N = -1;
    
//         for(int i = 0; i < 4; i++){
//             if(check_(nx + way[i][0] , ny + way[i][1] ) && vis[nx + way[i][0]][ny + way[i][1]] == 0 && map[nx + way[i][0]][ny + way[i][1]] < min){
//                 N = i;
//                 min = map[nx + way[i][0]][ny + way[i][1]];
//             }
//         }
//         cout << min << endl;
//         if(N == -1)break;
//         nx += way[N][0];
//         ny += way[N][1];
//         sum += map[nx][ny];
//         vis[nx][ny] = -1;
//     }
//     cout << sum << endl; 

//     return 0;
// }
#include<iostream>
#include<algorithm>
using namespace std;
int findmin(int& up, int& down, int& left, int& right, int& nowi, int& nowj) {
	int compare[4] = { up,down,left,right };
	sort(compare, compare + 4);
    //排序前後左右數值的大小
    //最小值有可能是-1（因為其他可以走的路的數值都會是正整數），所以要檢查
    //檢查後就return 數值跟位置
	if (compare[0] != -1) {
		nowi--;
        return up;
	}
	else if (compare[1] != -1) {
		nowi++;
        return down;
	}
	else if (compare[2] != -1) {
		nowj--;
        return left;
	}
	else if(compare[3] != -1){
        nowj++;
		return right;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int nums[101][101], min, nowi = 0, nowj = 0;
    //初始化，每格都填-1
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			nums[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> nums[i][j];
            if (nums[i][j] < min) {
				min = nums[i][j];
                //找出最小值
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (nums[i][j] == min) {
				nowi = i;
				nowj = j;
                //找出最小值的位置
			}
		}
	}
	int sum = nums[nowi][nowj];
	while (1) {
        nums[nowi][nowj] = -1;
		if (nums[nowi - 1][nowj] == -1 && nums[nowi][nowj - 1] == -1 && nums[nowi + 1][nowj] == -1 && nums[nowi][nowj + 1] == -1)break;
		//如果前後左右都不能走就break
        findmin(nums[nowi - 1][nowj], nums[nowi][nowj - 1], nums[nowi + 1][nowj], nums[nowi][nowj + 1], nowi, nowj);
		//找周圍最小值
        cout << nowi << " " << nowj << endl;
        sum += nums[nowi][nowj];
        nums[nowi][nowj] = -1;
        //把最小值加上去
	}
	cout << sum << endl;


	return 0;
}