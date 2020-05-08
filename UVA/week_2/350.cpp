#include<iostream>
#include<set>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    long long Z, I, M, L,cal = 0;
    while(cin >> Z >> I >> M >> L){
        if(Z == 0 && I == 0 && M == 0 && L == 0)return 0;
        set<long long> vis;
        vis.clear();
        long long count = 1;
        L = (Z * L + I) % M;
        vis.insert(L);
        while(1){
            L = (Z * L + I) % M;
            if(vis.find(L) == vis.end()){
                vis.insert(L);
                count++;
            }else{
                break;
            }
        }
        cout << "Case " << ++cal << ": " << count << endl;
    }

    return 0;
}