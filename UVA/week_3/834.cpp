#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

vector <int> ans;

void Fraction(int a, int b){
    int b0 = a / b;
    ans.push_back(b0);
    if(a % b == 0)return;
    a = a - b0 * b;
    swap(a, b);
    Fraction(a, b);
}


int main(){
    int a, b;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> a >> b){
        ans.clear();
        Fraction(a, b);
        cout << "[" << ans[0] << ";";
        for(int i = 1; i < ans.size(); i++){
            if(i == ans.size() - 1)cout << ans[i];
            else cout << ans[i] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}