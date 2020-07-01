#include<cstdio>
#include<utility>
#include<algorithm>
#include<cmath>
#include<iostream>

#define ll long long
#define endl '\n'
#define N 10000
#define Pair pair<int, int>


using namespace std;


int dir(Pair& a, Pair& b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
bool cmp(const Pair& a, const Pair& b){ 
    return a.second < b.second;
}

int main(){
    int n, i, j;
    Pair one[N], three[N];
    while (cin >> n && n != EOF){
        getchar();
        int s = 0, t = 0;
        char c;
        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                c = getchar();
                if (c == '1'){
                    one[s].first = i, one[s++].second = j;
                }else if (c == '3'){
                    three[t].first = i, three[t++].second = j;
                }
            }
            getchar();
        }

        int max = 0;
        sort(three, three + t, cmp);
        for (i = 0; i < s; i++){  
            int idx = lower_bound(three, three + t, one[i], cmp) - three;
            int d = 1e9;

            for (j = idx; j < t; j++){
                if (one[i].second + d < three[j].second)
                    break;

                int temp = dir(three[j], one[i]);
                if (temp < d)
                    d = temp;
            }

            for (j = idx - 1; j >= 0; j--){
                if (one[i].second - d > three[j].second)
                    break;

                int temp = dir(three[j], one[i]);
                if (temp < d)
                    d = temp;
            }

            if (d > max)
                max = d;
        }
        cout << max << endl;
    }


    return 0;
}
