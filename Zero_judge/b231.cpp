#include <iostream>
#include <queue>

#define ll long long
#define endl '\n'

using namespace std;
 
int main(){
    int n, p, b;
    priority_queue <pair<int, int> > pq;
    while (cin >> n){
        for (int i = 0; i < n; i++){
            cin >> p >> b;
            pq.push(make_pair(b, p));
        }
        int cpt = 0;
        int ans = 0;
        while (!pq.empty()){
            cpt += pq.top().second;
            ans = max(ans, cpt + pq.top().first);
            pq.pop();
        }
        cout << ans << endl << endl;
    }
    return 0;
}