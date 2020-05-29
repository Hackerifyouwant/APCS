#include<iostream>
#include<sstream>

#define ll long long
#define endl '\n'

using namespace std;

int set[1005];
int N;

void initial(){
    for(int i = 1; i <= N; i++){
        set[i] = i;
    }
}

void union_(int i, int j){
    if(set[i] == set[j])return ;

    int gx = set[i], gy = set[j];
    for(int i = 1; i <= N; i++){
        if(set[i] == gx){
            set[i] = gy;
        }
    }
}

int main(){
    int n;
    while(cin >> n && n !=EOF){
        getchar();
        while(n--){
            cin >> N;
            initial();
            string S;
            getchar();
            int correct = 0, uncorrect = 0;

            while(getline(cin, S) && S != ""){
                stringstream ss;
                char c;
                int I, J;
                ss << S;
                ss >> c;
                ss >> I;
                ss >> J;
                if(c == 'c'){
                    union_(I, J);
                }else{
                    if(set[I] == set[J])correct ++;
                    else uncorrect++;
                }
                //cout << endl << "%%" << set[I] << " " << set[J] << endl;
                    
            }
            cout << correct << ',' << uncorrect << endl;
            if(n)cout << "" << endl;
        } 
    }
    

    return 0;
}

