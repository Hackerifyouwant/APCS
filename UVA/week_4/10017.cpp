#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

int n, m;
int num = 0;

void Move(vector<int> &a, vector<int> &c, vector<int> *manage[]){
    c.push_back(a.back());
    a.pop_back();

    cout << endl;
    cout << "A=>";
    if(manage[0]->size())cout << "  ";
    
    for(int i = 0; i < manage[0]->size(); i++){
        cout << " " << (*manage[0])[i];
    }
    cout << endl;


    cout << "B=>";
    if(manage[1]->size())cout << "  ";
    for(int i = 0; i < manage[1]->size(); i++){
        cout << " " << (*manage[1])[i];
    }
    cout << endl;


    cout << "C=>";
    if(manage[2]->size())cout << "  ";
    for(int i = 0; i < manage[2]->size(); i++){
        cout << " " << (*manage[2])[i];
    }
    cout << endl;
    num++;
}

void Hanoi(int n, vector<int> &a, vector<int> &b, vector<int> &c, vector<int> *manage[]){
    if(n == 1 && num < m)Move(a, c, manage);
    else if(num < m){
        Hanoi(n - 1, a, c, b, manage);
        if(num >= m)return;
        Move(a, c, manage);
        if(num >= m)return;
        Hanoi(n - 1, b, a, c, manage);
    }
}



int main(){
    int count = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        num = 0;
        cout << "Problem #" << count++ << endl << endl;
        vector<int> a, b, c;
        vector<int> *manage[3] = {&a, &b, &c};
        cout << "A=>  " ; 
        for(int i = n; i > 0; i--){
            a.push_back(i);
            cout << " " << i;
        }
        cout << endl << "B=>" << endl << "C=>" << endl;
        Hanoi(n, a, b, c, manage);
        cout << endl;
    }
    return 0;
}

