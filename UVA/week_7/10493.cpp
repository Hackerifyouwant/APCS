#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){
        if(N == 0 && M == 0)break;
        cout << N << " " << M << " ";
        if(M == 1 && N == 1)cout << "Multiple" << endl;
        else if(N == 1 || (N * M - 1) % (N - 1))cout << "Impossible" << endl;
        else cout << (N * M - 1) / (N - 1) << endl;; 
    }   
    return 0;
}