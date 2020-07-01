#include<iostream>
#include<map>
#include<cstring>

#define ll long long
#define endl "\n"

using namespace std;

string S[105];
string s;
string news;
string path[105];
map<string, int>string_to_index;
int cnt;
bool vis[105];

void f(int level, int target){
    if(level == target){
        for(int i = 0; i < level; i++){
            if(i != level - 1)cout << path[i] << ", ";
            else cout << path[i];
        }
        cout << endl;
        return ;
    }
    for(int i = 0; i < cnt; i++){
        if(vis[i] == 0){
            if(string_to_index[path[level - 1]] <= i){
                vis[i] = 1;
                path[level] = S[i];
                f(level + 1, target);
                vis[i] = 0;
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    getchar();
    for(int i = 0; i < N; i++){
        s.clear();
        news.clear();
        cnt = 0;
        string_to_index.clear();
        memset(vis, false, sizeof(vis));
        int a, b;
        
        if(i == 0)getchar();
        getline(cin, s);
        
        while(getline(cin, news)){
            if(news == "" || news[0] == EOF)break;
            S[cnt] = news;
            string_to_index[news] = cnt;
            cnt++;
        }
        if(s.size() == 3){
            a = s[0] - '0';
            b = s[2] - '0';
            for(int i = a; i <= b; i++){
                if(i != a)cout << endl;
                cout << "Size " << i << endl;
                f(0, i);
            }
        }else{
            if(isdigit(s[0])){
                a = s[0] - '0';
                for(int i = 1; i <= a; i++){
                    if(i != 1)cout << endl;
                    cout << "Size " << i << endl;
                    f(0, i);
                }
            }else {
                for(int i = 1; i <= cnt; i++){
                    if(i != 1)cout << " * "<< endl;
                    cout << "Size " << i  << endl;
                    f(0, i);
                }
            }
        }
        //cout << "&&" << i << endl;
        cout << endl;
        if(i != N - 1)cout << endl;
    }
    return 0;
}

