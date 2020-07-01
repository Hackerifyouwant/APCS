#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int s[105];
        for(int j = 0; j < n; j++){
            cin >> s[j];
        }
        sort(s, s + n);
        int min = 1e9;
        for(int j = 0; j < n - 1; j++){
            int result = s[j + 1] - s[j];
            if(min > result){
                min = result;
            }
        }
        cout << min << endl;
    }


    return 0;
}