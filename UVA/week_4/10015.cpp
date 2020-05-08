#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'
#define Max 3502

using namespace std;

int tbl[4005];
int prime_[4005];
int prime_C = 0;
int josephi[4005];
int index_ = 0;
int n;
bool vis[4005];

void prime(){
    for(int i = 2; i <= Max; i++){
        if(tbl[i] == 0){
            prime_[prime_C] = i;
            prime_C++;
        }
        for(int j = i + i; j <= Max; j += i){
            tbl[j] = 1;
        }
    }
}

int jos(int depth){
    int index = 0;
    for(int i = 0; i < depth; i++){
        index = index + prime_[i];
        vis[] = 1;
    }
}


int main(){
    prime();
    while(cin >> n && n != 0){
        jos(n);
        //     cout << jos(n - 1) << endl;
    }
    return 0;
}