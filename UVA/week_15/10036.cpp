#include<iostream>
#include<string.h>
#include<math.h>

#define ll long long
#define endl '\n'

using namespace std;

int a[10004];
int f[10004][104];

int main(){
    int T, N, K;
    while(cin >> T && T != EOF){
        while(T--){
            cin >> N >> K;
            for(int i = 0; i < N; i++){
                cin >> a[i];
            }
            for(int i = 0; i < N; i++){
                a[i] = abs(a[i]) % K;
            }
            memset(f, 0, sizeof(f));
		    f[0][0] = 1;
            for (int i = 0; i < N; i++ ){
                for (int j = 0; j < K; j++){
                    if (f[i][j]) {
                        f[i + 1][(j + K + a[i]) % K] = 1;
                        f[i + 1][(j + K - a[i]) % K] = 1;
                    }
                }
            }
            if(f[N][0])cout << "Divisible" << endl;
            else cout << "Not divisible" << endl;
        }
    }
    return 0;
}