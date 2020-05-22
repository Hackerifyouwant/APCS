#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'
#define maxn 1000000

int p[maxn + 5], ans[maxn + 5];

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i <= sqrt(maxn); i++){
        if(p[i] == 0){
            for(int j = i * i ; j <= maxn; j += i){
                if(p[j] == 0)p[j] = i;
            }
        }
    }
    for(int i = 0; i <= maxn; i++){
        if (p[i] == 0) p[i] = i;
    }
	int nowi, nownum = 0;
    for(int i = 1; i <= maxn; i++){
        int x = i, num = 1;
        while(x > 1){
            int tmp = p[x], cnt = 0;
            while((x % tmp) == 0){
                cnt++;
                x /= tmp;
            }
            num *= (cnt + 1);
        }
        if(num >= nownum){
            ans[i] = i;
            nowi = i;
            nownum = num;
        }else{
            ans[i] = nowi;
        }
    }
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}



