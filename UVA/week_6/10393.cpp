#include<iostream>
#include<cstdio>
#include<string>
#include<set>

#define ll long long
#define endl '\n'

using namespace std;

int f, n, m, longest_size;
string hurt, boss;
set<string> longest_str;
string fingers[10] = {"qaz", "wsx", "edc", "rfvtgb", " ", " ", "yhnujm", "ik,", "ol.", "p;/"};

int main(){
    while(cin >> f >> n){
        hurt.clear();
        longest_str.clear();
        longest_size = 0;
        for(int i = 0; i < f; i++){
            cin >> m;
            hurt = hurt + fingers[m - 1];
        }
        for(int i = 0; i < n; i++){
            cin >> boss;
            if(hurt.find_first_of(boss) == string::npos){
                if(boss.size() > longest_size){
                    longest_size = boss.size();
                    longest_str.clear();
                    longest_str.insert(boss);
                }else if(boss.size() == longest_size){
                    longest_str.insert(boss);
                }
            }
        }
        cout << longest_str.size() << endl;
        for(auto output : longest_str){
            cout << output << endl;
        }
    }
    return 0;
}

