#include<iostream>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

int main(){
    int N;
    while(cin >> N && N != 0){
        string str[105];
        for(int i = 0; i < N; i++){
            cin >> str[i];
        }
        sort(str, str + N, cmp);
        for(int i = 0; i < N; i++){
            cout << str[i];
        }
        cout << endl;
    }


    return 0;
}
