#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

string pre, in;

void post(int pres, int pren, int ins, int inn){
    if(pres > pren)return ;
    if(ins > inn)return ;
    char root = pre[pres];
    int i = ins;
    int add = 0;
    while(in[i] != root){
        i++;
        add++;
    }
    //cout << pres << " " << pren << " " << ins << " " << inn << endl; 
    post(pres + 1, pres + add, ins, ins + add - 1);
    post(pres + add + 1, pren, ins + add + 1, inn);
    cout << root;
    
    return ;
}


int main(){
    while(cin >> pre >> in){
        post(0, (int)pre.size() - 1,0, (int)in.size() - 1);
        cout << endl;
    }
    return 0;
}