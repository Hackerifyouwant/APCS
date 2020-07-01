#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;
int way[2] = {1, 2};

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        string s;
        cin >> N >> s;
        int scarecrow = 0;
        for(int j = 0; j < s.length(); j++){
            if( s[j] == '.' ){
                scarecrow++;
                if(j + 1 < s.length())s[j + 1] = '#';
                if(j + 2 < s.length())s[j + 2] = '#';
            }
        }
        cout << "Case " << i + 1 << ": " << scarecrow << endl;
    }
    return 0;
}