#include<iostream>
#include<sstream>
#include<map>
#include<algorithm>

#define ll long long 
#define endl '\n'

using namespace std;
struct Max{
    int count = 0;
    string SS;
};

bool cmp(Max r, Max l){
    return r.count > l.count;
}

char transfer(char c){
    if(c <= 'Z' && c >= 'A'){
        c = c + 'a' - 'A';
    }
    return c;
}

int main(){
    int K, E;
    int col = 1;
    while(cin >> K >> E){
        map<string, bool> key;
        string excuse[10005];
        for(int i = 0; i < K; i++){
            string s;
            cin >> s;
            key[s] = 1;
        }
        getchar();
        for(int i = 0; i < E; i++){
            getline(cin, excuse[i]);
        }
        Max C[10005];
        for(int i = 0; i < E; i++){
            string S = "";
            C[i].SS = excuse[i];
            for(auto j : excuse[i]){
                if(isalpha(j)) j = transfer(j);
            
                if(isalpha(j))S += j;
                else {
                    if(key[S] == 1){
                        C[i].count ++;
                    }
                    S = "";
                }
            }
        }
        sort(C, C + E, cmp);
        cout << "Excuse Set #" << col++ << endl;
        cout << C[0].SS << endl;
        for(int i = 1; i < E; i++){
            if(C[i].count == C[0].count)cout << C[i].SS << endl;
        }
        cout << endl;
    }

    return 0;
}