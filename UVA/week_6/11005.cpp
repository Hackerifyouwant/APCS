#include<iostream>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;

map<int, int> value;

int main(){
    int N;
    cin >> N;
    int cnt = 1;
    while(N--){
        for(int i = 0; i < 36; i++){
            int a;
            cin >> a;
            value[i] = a;
        }
        int n;
        cin >> n;
        cout << "Case " << cnt++ << ":" << endl;
        while(n--){
            int a;
            cin >> a;
            int mn = 0x7FFFFFFF;
            map<int, int> ans;
            for(int i = 2; i <= 36; i++){
                int x = a;
                int cost = 0;
                while(x > 0){
                    cost += value[x % i];
                    x /= i;
                }
                mn = min(mn, cost);
                ans[i] = cost;
                //cout << i << " " << cost << endl;
            }
            cout << "Cheapest base(s) for number " << a << ":";
            for(int i = 2; i <= 36; i++){
                if(ans[i] == mn)cout << " " << i;
            }
            cout << endl;
        }
        if(N != 0)cout << endl;
    }
    return 0;
}

