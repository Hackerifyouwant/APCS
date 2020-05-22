#include<iostream>
#include<map>

#define ll long long
#define endl '\n'

using namespace std;

char transfer(char c){
    if(c == 'A' || c == 'B' || c == 'C')return '2';
    if(c == 'D' || c == 'E' || c == 'F')return '3';
    if(c == 'G' || c == 'H' || c == 'I')return '4';
    if(c == 'J' || c == 'K' || c == 'L')return '5';
    if(c == 'M' || c == 'N' || c == 'O')return '6';
    if(c == 'P' || c == 'R' || c == 'S')return '7';
    if(c == 'T' || c == 'U' || c == 'V')return '8';
    if(c == 'W' || c == 'X' || c == 'Y')return '9';
}

int main(){
    int N;
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        map<string, int> Search;
        getchar();
        for(int i = 0; i < n; i++){
            string s;
            string SS = "";
            getline(cin, s);
            for(char c : s){
                if(SS.size() == 3)SS = SS + '-';
                if(isalpha(c))SS = SS + transfer(c);
                else if(isdigit(c))SS = SS + c;
                //cout << SS << endl;
            }
            if(Search[SS] != 0)Search[SS] ++;
            else Search[SS] = 1;
        }
        map<string, int>::iterator itr;
        bool check = 0;
        for(itr = Search.begin() ; itr != Search.end(); itr++){
            if(itr->second > 1){
                cout << itr->first << " " << itr->second << endl;
                check = 1;
            }
        }
        if(check == 0)cout << "No duplicates." << endl;
        if(N != 0)cout << endl;
    }
    return 0;
}