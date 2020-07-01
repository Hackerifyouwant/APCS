// #include<iostream>
// #include<math.h>
// #include<iomanip>

// #define ll long long
// #define endl '\n'

// using namespace std;

// double x[202], y[202];
// double dist[202][202];

// int main(){
//     int n, t = 1;
//     int cnt = 1;
//     while(cin >> n && n){
//         for(int i = 0; i < n; i++){
//             cin >> x[i] >> y[i];
//         }
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
// 			    dist[j][i] = dist[i][j];
//             }
//         }

//         for(int k = 0; k < n; k++){
//             for(int i = 0; i < n; i++){
//                 for(int j = 0; j < n; j++){
//                     double max;
//                     if(dist[i][k] > dist[k][j]){
//                         max = dist[i][k];
//                     }else{
//                         max = dist[k][j];
//                     }
//                     if(dist[i][j] > max){
//                         dist[i][j] = max;
//                     }
//                 }
//             }
//         }
//         cout << "Scenario #" << cnt++ << endl;
//         cout << fixed << setprecision(3) << "Frog Distance = " << dist[0][1] << endl << endl;
//     }

//     return 0;
// }


#include<string.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<iomanip>
 
#define ll long long
#define endl '\n'

double x[202], y[202];
double dist[202][202];

using namespace std;
 
int main(){
	int n, t = 1;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++) {
                dist[j][i] = dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            }
        }
		for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(max(dist[i][k], dist[k][j]), dist[i][j]);
                }
            }
        }

		cout << "Scenario #" << t++ << endl;
        cout << fixed << setprecision(3) << "Frog Distance = " << dist[0][1] << endl << endl;
	}
    return 0;
}