// // #include <iostream>

// // #define ll long long
// // #define endl '\n'

// // using namespace std;
 
// // int main() {
// //     int N, M, K;
// //     while (cin >> N >> M >> K){
// //         int ans = 0;
// //         for (int i = N - K + 1; i <= N; i++){
// //             ans = (ans + M) % i;
// //         }
// //         cout << ans + 1 << '\n';
// //     }
 
// //     return 0;
// // }
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
// 	int n, m, k, now;
// 	vector<int> p;
// 	while (cin >> n >> m >> k) {
// 		p.clear();
// 		for (int i = 1; i <= n; i++) {
// 			p.push_back(i);
// 		}
// 		now = 0;
// 		for (int i = 0; i < k; i++) {
// 			now = (now + m - 1) % p.size();
// 			p.erase(p.begin() + now);//刪除被炸的人
// 		}
// 		now = now%p.size();
//                 cout << p[now]<<endl;
// 	}
// }
#include<iostream>
#include<string.h>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n, m, k;
    int ans;
    cin >> n >> m >> k;
    ans = 0;
    for(int i = n - k + 1; i <= n; i++){
        ans = (ans + m) % i;
    }
    cout << ans + 1 << endl;

    return 0;
}