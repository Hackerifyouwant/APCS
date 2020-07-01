#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    vector <int> odd, even;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int a[105];
        even.clear();
        odd.clear();
        for(int j = 0; j < n; j++){
            cin >> a[j];
            if(a[j] % 2 == 0)even.push_back(a[j]);
            else odd.push_back((a[j]));
        }
        if(even.size() % 2 == 0 && odd.size() % 2 == 0){
            cout << "YES" << endl;
        }else{
            bool check = 0;
            for(int m = 0; m < odd.size() && check == 0; m++){
                for(int n = 0; n < even.size(); n++){
                    if(abs(odd[m] - even[n]) == 1){
                        check = 1;
                        break;
                    }
                }
            }
            if(check == 0)cout << "NO" << endl;
            else cout << "YES" << endl;
        }

    }
    return 0;
}

